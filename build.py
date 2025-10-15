from subprocess import call

toolchain = "riscv64-none-elf-"
gcc_options = "-ffreestanding -nostdlib -mcmodel=medany -Os"

print("Building...")
if call("{}gcc {} -c src/*.c src/*/*.c -I include".format(toolchain, gcc_options), shell=True):
    print("Failed during building")
    exit()

print("Turning into static library...")
if call("{}ar cr libc.a *.o".format(toolchain), shell=True):
    print("Failed during archiving")

print("Done")
