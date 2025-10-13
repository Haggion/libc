# libc for Haggion
This repository contains a C standard library implementation for the Haggion operating system.

## Building
Prebuilt archives can be found on the releases page of this repository. Alternatively, you can easily build it yourself using the `build.py` script. Merely change the `toolchain` variable to contain the prefix of whatever toolchain you use to build for RISCV, and the script ought to do the rest. If this is successful, you should end up with a `libc.a` file in the same directory, which you can link with to create a runnable binary for Haggion.

## Usage
At the moment Haggion does not feature a dynamic linker, so libc needs to be linked manually. You can do so by just adding the `libc.a` file during your linking process. Here's an example of doing so:

`riscv64-none-elf-ld -T linker.ld -o out.elf main.o libc.a`

Do note that your linker script should specify .text.\_start being at the very start of your program, to ensure that is ran first.