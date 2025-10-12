#pragma once

#define STR(m) #m
#define XSTR(m) STR(m)

#define SYSCALL(addr) {\
            asm ("li t0, " XSTR(addr)); \
            asm ("jalr ra, t0, 0"); \
        }
