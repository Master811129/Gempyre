@echo off
if "%VSCMD_ARG_HOST_ARCH%"=="x64" goto pass_ver
echo Execute in the x64 Native tools command prompt.
echo "msvc_install.bat <DIR>"
echo DIR is optional and points to the install dir, defaults defined in GnuInstallDirs where the find_package should find it.
echo Warning: if a DIR is a relative directory, it refers to msvc_build folder. 
goto exit
:pass_ver

if not "%1"=="" set PREFIX=-DCMAKE_INSTALL_PREFIX=%1
if "%1"=="" set PREFIX=

if not exist "msvc_build" mkdir msvc_build

pushd msvc_build
if exist "install.log" del install.log
cmake .. -DCMAKE_BUILD_TYPE=Debug -DHAS_AFFILIATES=OFF -DHAS_TEST=OFF -DHAS_EXAMPLES=OFF %PREFIX%
if %ERRORLEVEL% NEQ 0 popd && exit /b %ERRORLEVEL%
cmake --build . --config Debug
if %ERRORLEVEL% NEQ 0 popd && exit /b %ERRORLEVEL%
set BUILD_PATH=%CD%
popd
echo Start an elevated prompt for an install.
powershell -Command "Start-Process scripts\win_inst.bat -Verb RunAs -ArgumentList "%BUILD_PATH%,Debug"

pushd msvc_build
cmake .. -DCMAKE_BUILD_TYPE=Release -DHAS_AFFILIATES=OFF -DHAS_TEST=OFF -DHAS_EXAMPLES=OFF %PREFIX%
cmake --build . --config Release
set BUILD_PATH=%CD%
popd
echo Start an elevated prompt for an install.
powershell -Command "Start-Process scripts\win_inst.bat -Verb RunAs -ArgumentList %BUILD_PATH%"

echo done
:exit
