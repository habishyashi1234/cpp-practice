#import os
#os.system("mkdir -p build && protoc --proto_path=proto --cpp_out=build proto/position.proto && cmake -B build -S . && cmake --build build")
import subprocess

def run_command(cmd, desc):
    print(f"Running: {desc}")
    subprocess.run(cmd, check=True)

try:
    run_command(
        ["mkdir", "-p", "build"],
        "Making the build directory if it is not present"
    )
    run_command(
        ["cmake", "-B", "build", "-S", "."],
        "Configuring project with CMake"
    )
    run_command(
        ["cmake", "--build", "build"],
        "Building the project"
    )
    print(" Build completed successfully.")
except subprocess.CalledProcessError as e:
    print(f"Error during: {e.cmd}")
    exit(1)