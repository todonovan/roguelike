#pragma once

#include <stdint.h>
#include <windows.h>

// Macros

#define HACKY_ASSERT(expr) if(!(expr)) { *(uint8_t *)0 = 0;}

#define KILOBYTES(num) ((num) * 1024)
#define MEGABYTES(num) ((num) * 1024 * 1024)
#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

// Constants

#define GAME_PERM_MEMORY_SIZE MEGABYTES(256)
#define GAME_TRANSIENT_MEMORY_SIZE MEGABYTES(1024)


struct PlatformBitmapBuffer
{
    BITMAPINFO info_struct;
    void *memory;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bytes_per_pixel;
};

bool read_file_into_buffer(LPCTSTR file_name, void *buffer, DWORD bytes_to_read);
bool write_buffer_into_file(LPCSTR file_name, void *buffer, DWORD bytes_to_write);