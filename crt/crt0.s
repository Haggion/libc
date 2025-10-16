.section .text._start

.global _start
_start:
   addi sp, sp, -16
   sd   ra, 8(sp)

   la   t0, crt_init
   jalr ra, t0, 0

   ld   ra, 8(sp)
   addi sp, sp, 16
   ret
