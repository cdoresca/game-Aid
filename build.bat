@echo off
REM Build Script 

setlocal EnableDelayedExpansion

rem find all files

set files=
for /R %%f in (*.c) do(
    set files=!files! %%f
    echo %%f
)


set assembly=engine
set compilerFlags=-g -shared -Wvarags -Wall -Werror
set includeFlags=-Isrc -I%VULKAN_SDK%/Include
set linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
set defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

echo "Building %assembly%"

clang %files% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%

endlocal

pause
