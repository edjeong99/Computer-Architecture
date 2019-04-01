#include "cpu.h"

#define DATA_LEN 6

/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */

unsigned char cpu_ram_read(struct cpu *cpu){
  return cpu->ram[0];
}

void cpu_ram_write(struct cpu *cpu){
  
}

void cpu_load(struct cpu *cpu)
{
  char data[DATA_LEN] = {
    // From print8.ls8
    0b10000010, // LDI R0,8
    0b00000000,
    0b00001000,
    0b01000111, // PRN R0
    0b00000000,
    0b00000001  // HLT
  };

  int address = 0;

  for (int i = 0; i < DATA_LEN; i++) {
    cpu->ram[address++] = data[i];
  }

  // TODO: Replace this with something less hard-coded
}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB)
{
  switch (op) {
    case ALU_MUL:
      // TODO
      break;

    // TODO: implement more ALU ops
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1; // True until we get a HLT instruction
  unsigned char reg_num, val, IR, operandA, operandB, num_operands;

  while (running) {
    // TODO
    // 1. Get the value of the current instruction (in address PC).
    IR = cpu->ram[cpu->PC];
 
  // 2. Figure out how many operands this next instruction requires
    num_operands = IR >> 6;
    if(num_operands > 0){
      operandA = cpu->ram[cpu->PC + 1];
       printf("operandA  = %d\n", operandA);

    }
    if (num_operands > 1){
      operandB = cpu->ram[cpu->PC + 2];
      printf("operandB  = %d\n", operandB);
    }

   
    // 3. Get the appropriate value(s) of the operands following this instruction

    // 4. switch() over it to decide on a course of action.
        switch (IR) {

    // 5. Do whatever the instruction should do according to the spec.
    // 6. Move the PC to the next instruction.

            case LDI:               
                reg_num = operandA;
                val = operandB;

                cpu->registers[reg_num] = val;

                cpu->PC += 3;
                break;

           case PRN:
                reg_num = operandA;
                printf("register %d = %d\n", reg_num, cpu->registers[reg_num]);

                cpu->PC += 2;
                break;

            case HLT:
                running = 0;
                cpu->PC++;
                break;

            default:
                printf("Unrecognized instruction\n");
                exit(1);
                break;

    

  }
}
}
/**
 * Initialize a CPU struct
 */
void cpu_init(struct cpu *cpu)
{
  // TODO: Initialize the PC and other special registers

  cpu->PC = 0;
  memset(cpu->registers, 0, sizeof(cpu->registers)); 
  memset(cpu->ram, 0, sizeof(cpu->ram)); 
  

}
