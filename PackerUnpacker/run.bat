@echo off
echo Compiling...
javac -d bin src/main/java/packerunpacker/*.java
if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b
)
echo Running...
java -cp bin packerunpacker.Main
