int main();

__attribute__((section(".text._start"), naked))
void _start(void){
   asm("addi sp, sp, -0x10");
   asm("sd ra, 8(sp)");

   main();

   asm("ld ra, 8(sp)");
   asm("addi sp, sp, 0x10");
   asm("ret");
}
