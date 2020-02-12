@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

cl -MTd -nologo -fp:fast -Gm- -GR- -EHa -Od -Oi -WX -W4 -wd4456 -wd4505 -wd4201 -wd4200 -wd4100 -wd4189 -wd4505 -Z7 -FC -Fmroguelike.map ..\src\win32_roguelike.cpp /link -incremental:no -opt:ref user32.lib Winmm.lib Gdi32.lib -PDB:roguelike_%random%.pdb

popd