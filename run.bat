@echo off

set ser="_proj-cir-deb-86.exe"
set par="_ompproj-cir-deb-86.exe"
set out="out-cir-deb-86-ser-lenovo.txt"
set to=30

REM
REM :: SERIAL PROG RUNS ::
REM

for /L %%c in (10,10,90) DO (
echo %%c
cmd /C "%ser% %%c %%c %%c %%c >> %out%"
timeout %to%
)

for /L %%c in (100,100,900) DO (
echo %%c
cmd /C "%ser% %%c %%c %%c %%c >> %out%"
timeout %to%
)

REM for /L %%c in (1000,1000,9000) DO (
REM echo %%c
REM cmd /C "%ser% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )

REM
REM :: PARALLEL PROG RUNS ::
REM
set out="out-cir-deb-86-par-lenovo.txt"

for /L %%c in (10,10,90) DO (
echo %%c
cmd /C "%par% %%c %%c %%c %%c >> %out%"
timeout %to%
)

for /L %%c in (100,100,900) DO (
echo %%c
cmd /C "%par% %%c %%c %%c %%c >> %out%"
timeout %to%
)

REM for /L %%c in (1000,1000,9000) DO (
REM echo %%c
REM cmd /C "%par% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )

REM ==================================================

set ser="_proj-irc-deb-86.exe"
set par="_ompproj-irc-deb-86.exe"
set out="out-irc-deb-86-ser-lenovo.txt"
set to=30

REM
REM :: SERIAL PROG RUNS ::
REM

for /L %%c in (10,10,90) DO (
echo %%c
cmd /C "%ser% %%c %%c %%c %%c >> %out%"
timeout %to%
)

for /L %%c in (100,100,900) DO (
echo %%c
cmd /C "%ser% %%c %%c %%c %%c >> %out%"
timeout %to%
)

REM for /L %%c in (1000,1000,9000) DO (
REM echo %%c
REM cmd /C "%ser% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )

REM
REM :: PARALLEL PROG RUNS ::
REM
set out="out-irc-deb-86-par-lenovo.txt"

for /L %%c in (10,10,90) DO (
echo %%c
cmd /C "%par% %%c %%c %%c %%c >> %out%"
timeout %to%
)

for /L %%c in (100,100,900) DO (
echo %%c
cmd /C "%par% %%c %%c %%c %%c >> %out%"
timeout %to%
)

REM for /L %%c in (1000,1000,9000) DO (
REM echo %%c
REM cmd /C "%par% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )