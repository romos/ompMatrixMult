@echo off

set ser="proj-deb-86.exe"
set par="ompproj-deb-86.exe"
set out="out-deb-86-ser-lenovo.txt"
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

for /L %%c in (1000,1000,9000) DO (
echo %%c
cmd /C "%ser% %%c %%c %%c %%c >> %out%"
timeout %to%
)

REM REM
REM REM :: PARALLEL PROG RUNS ::
REM REM

REM for /L %%c in (10,10,90) DO (
REM echo %%c
REM cmd /C "%par% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )

REM for /L %%c in (100,100,900) DO (
REM echo %%c
REM cmd /C "%par% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )

REM for /L %%c in (1000,1000,10000) DO (
REM echo %%c
REM cmd /C "%par% %%c %%c %%c %%c >> %out%"
REM timeout %to%
REM )