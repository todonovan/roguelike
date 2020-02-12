#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <tchar.h>

#include "win32_roguelike.h"


struct InternalGameWindow
{
    HWND window_handle;
    RECT client_rect;
    HDC device_context;
    uint64_t width;
    uint64_t height;
};

static PlatformBitmapBuffer backbuffer;
static InternalGameWindow game_window;

void update_window_dimensions(HWND window_handle)
{
    game_window.window_handle = window_handle;
    game_window.client_rect = {};
    GetClientRect(game_window.window_handle, &(game_window.client_rect));
    game_window.width = game_window.client_rect.right;
    game_window.height = game_window.client_rect.bottom;
}

void resize_dib_section(int width, int height)
{
    if (backbuffer.memory)
    {
        VirtualFree(backbuffer.memory, 0, MEM_RELEASE);
    }

    backbuffer.width = width;
    backbuffer.height = height;

    backbuffer.info_struct.bmiHeader.biSize = sizeof(backbuffer.info_struct.bmiHeader);
    backbuffer.info_struct.bmiHeader.biWidth = backbuffer.width;
    backbuffer.info_struct.bmiHeader.biHeight = backbuffer.height; // Negative to ensure top-down DIB
    backbuffer.info_struct.bmiHeader.biPlanes = 1;
    backbuffer.info_struct.bmiHeader.biBitCount = 32;
    backbuffer.info_struct.bmiHeader.biCompression = BI_RGB;
    backbuffer.bytes_per_pixel = 4; // 4 bytes per pixel to keep dword aligned
    backbuffer.pitch = width * backbuffer.bytes_per_pixel;
    int bitmap_memory_size = backbuffer.width * backbuffer.height * backbuffer.bytes_per_pixel;

    backbuffer.memory = VirtualAlloc(0, bitmap_memory_size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
}

inline void clear_offscreen_buffer()
{
    if (!(backbuffer.memory)) return;
	ZeroMemory(backbuffer.memory, backbuffer.height * backbuffer.width * 4);
}

void draw_into_window(HDC draw_dc)
{
    StretchDIBits(draw_dc, 0, 0, (int)game_window.width, (int)game_window.height, 0, 0, backbuffer.width,
                  backbuffer.height, backbuffer.memory, &(backbuffer.info_struct), DIB_RGB_COLORS, SRCCOPY);
}

// Returns true if read was successful, false otherwise
bool read_file_into_buffer(LPCSTR file_name, void *buffer, DWORD bytes_to_read)
{
    DWORD num_bytes_read = 0;
    HANDLE file = CreateFileA(file_name, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
    if (ReadFile(file, buffer, bytes_to_read, &num_bytes_read, 0))
    {
        CloseHandle(file);
        return num_bytes_read == bytes_to_read;
    }
    else
    {
        CloseHandle(file);
        return false;
    }
}

// Returns true if the write was successful, false otherwise
// Note that calling this function will truncate the associated file
bool write_buffer_into_file(LPCSTR file_name, void *buffer, DWORD bytes_to_write)
{
    DWORD num_bytes_written = 0;
    HANDLE file = CreateFileA(file_name, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);
    if (WriteFile(file, buffer, bytes_to_write, &num_bytes_written, 0))
    {
        CloseHandle(file);
        return num_bytes_written == bytes_to_write;
    }
    else
    {
        CloseHandle(file);
        return false;
    }
}

LRESULT CALLBACK RoguelikeWindowCallback(HWND wind_handle, uint32_t message, WPARAM w_param, LPARAM l_param)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_PAINT:
        {

        } break;
        case WM_CLOSE:
        case WM_DESTROY:
        {
            PostQuitMessage(0);
        } break;
        case WM_KEYDOWN:
        {
            switch (w_param)
            {
                case VK_UP:
                {
                    OutputDebugString("Up arrow");
                } break;
            }
        } break;
        default:
        {
            result = DefWindowProc(wind_handle, message, w_param, l_param);
        } break;
    }

    return result;
}

int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int cmd_show)
{
    WNDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    window_class.lpfnWndProc = &RoguelikeWindowCallback;
    window_class.lpszClassName = "RoguelikeWindowClass";

    if (RegisterClass(&window_class))
    {
        HWND window_handle = CreateWindowEx(0, window_class.lpszClassName, "Roguelike", WS_OVERLAPPEDWINDOW|WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, instance, 0);

        if (window_handle)
        {
            // Initial set up code here
            game_window = {};
            game_window.window_handle = window_handle;
			game_window.client_rect = {};
			update_window_dimensions(window_handle);
            resize_dib_section(1980, 1020);

            MSG message;
            for (;;)
            {
                while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
                {
                    if (message.message == WM_QUIT) { return 0; }

                    TranslateMessage(&message);
                    DispatchMessage(&message);
                }
                clear_offscreen_buffer();

                // Input
                // getchar();

                // update in game code;

                // render
                HDC window_dc = GetDC(window_handle);
                draw_into_window(window_dc);
                ReleaseDC(window_handle, window_dc);
            }
        }
    }

    return 0;
}