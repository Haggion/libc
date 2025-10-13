from subprocess import call

toolchain = "riscv64-none-elf-"
gcc_options = "-ffreestanding -nostdlib -mno-relax -g -mcmodel=medany"

print("Building...")
print(call("{}gcc {} -c src/*/* -I include".format(toolchain, gcc_options), shell=True))

print("Turning into static library...")
print(call("{}ar cr libc.a *.o".format(toolchain), shell=True))
print("Done")
