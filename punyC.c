/*
 * Compilation:  gcc -Wall -Wextra -std=c99 -g punyC.c -o punyC
 * run: ./punyC
 * refrence: punycomputer simulator pdf
 *  Works. Finished code.
 */

#include <stdlib.h>
#include <stdio.h>

/* Opcodes */
#define ADD 0
#define DEC 1
#define SET 2
#define JMP 3
#define JZ 4
#define JNZ 5
#define CALL 6
#define RET 7

/* CPU data registers */
#define R0 0
#define R1 1

/* CPU registers */
int r[2];
int pc;
int ir;
int ra;

/* Instruction memory */
#define PROG_MEM_SIZE 16
char instr[PROG_MEM_SIZE];

/* Masks */
#define MASK_8BITS 255
#define MASK_4BITS 15

void load_prog1();
void load_prog2();
// void run_prog(); //wrong prototype call
void run_prog(int sim_time);

int main() // originally void
{
    printf("\nProgram 1:\n");
    load_prog1();
    run_prog(20); /* Simulate for 20 instructions */

    printf("\n\nProgram 2:\n");
    load_prog2();
    run_prog(24);
}

int get_bit(int n, int bit_pos)
{
    return (n >> bit_pos) & 1;
}

int get_imm(int n)
{
    return n & MASK_4BITS;
}

void instr_cycle()
{
    int ir = MASK_8BITS & (int)(instr[pc]);
    pc = (pc + 1) & 0x0F;          // PC wraps within 4-bit memory bounds (0-15);
    int opcode = (ir >> 5) & 0x07; //// Extract bits 7, 6, 5

    switch (opcode)
    {
    case ADD:
        r[get_bit(ir, 4)] = r[get_bit(ir, 3)] + r[get_bit(ir, 2)];
        break;
    case DEC:
        r[get_bit(ir, 4)] = r[get_bit(ir, 4)] - get_imm(ir);
        break;
    case SET:
        r[get_bit(ir, 4)] = get_imm(ir);
        break;
    case JMP:
        pc = get_imm(ir);
        break;
    case JZ:
        if (r[get_bit(ir, 4)] == 0)
        {
            pc = get_imm(ir);
        }
        break;
    case JNZ:
        if (r[get_bit(ir, 4)] != 0)
        {
            pc = get_imm(ir);
        }
        break;
    case CALL:          // TODO: Call address type A
        ra = pc;        // save return address in ra
        pc = ir & 0x0F; // jump to target subroutine address
        // pc = get_imm(ir); // jump to target subroutine address
        break;

    case RET:           // TODO
        pc = ra & 0x0F; //// Step 1: Restore program counter from RA
        break;

    default:
        printf("Error: Unrecognized opcode %d\n", opcode);
        // printf("Invalid instruction!\n");
        break;
    }
}

void run_prog(int sim_time)
{
    printf("Simulation:\n");
    pc = 0; /* Initialize registers */
    r[0] = 0;
    r[1] = 0;
    /* Execute instructions */
    for (int t = 0; t < sim_time; t++)
    {
        printf("t=%2d: pc=%d, R0=%d, R1=%d\n", t, pc, r[0], r[1]);
        instr_cycle();
    }
}

char set_opcode(int opcode)
{
    return (char)(opcode << 5);
}

char set_bit(char c, int bit_val, int bit_pos)
{
    if (bit_val == 0)
    {
        return c & ((char)(~(1 << bit_pos)));
    }
    else
    {
        return c | ((char)(1 << bit_pos));
    }
}

char set_imm(char c, int imm)
{
    char clear_bits = (char)(~15);
    return (c & clear_bits) | ((char)imm);
}

char instr_typeA(int opcode, int imm)
{
    char i = set_opcode(opcode);
    i = set_imm(i, imm);
    return i;
}

char instr_typeB(int opcode, int dst, int imm)
{
    char i = set_opcode(opcode);
    i = set_bit(i, dst, 4);
    i = set_imm(i, imm);
    return i;
}

char instr_typeC(int opcode, int dst, int src1, int src2)
{
    char i = set_opcode(opcode);
    i = set_bit(i, dst, 4);
    i = set_bit(i, src1, 3);
    i = set_bit(i, src2, 2);
    return i;
}

void display_instr(char c)
{
    int i = (int)c;
    i = i & MASK_8BITS;
    printf("opcode=%d, ", i >> 5);
    printf("b[4]=%d, ", (i >> 4) & 1);
    printf("b[3..0]=%d%d%d%d, ", (i >> 3) & 1, (i >> 2) & 1, (i >> 1) & 1, i & 1);
}

void display_prog()
{
    printf("Program:\n");
    for (int i = 0; i < PROG_MEM_SIZE; i++)
    {
        printf("instr[%2d]: ", i);
        display_instr(instr[i]);
        printf("\n");
    }
}

void load_prog1()
{
    for (int i = 0; i < PROG_MEM_SIZE; i++)
    { /* Initialize program memory */
        instr[i] = (char)0;
    }

    instr[0] = instr_typeB(SET, R1, 0);
    instr[1] = instr_typeB(SET, R0, 3);
    instr[2] = instr_typeA(JZ, 0);
    instr[3] = instr_typeC(ADD, R1, R1, R0);
    instr[4] = instr_typeB(DEC, R0, 1);
    instr[5] = instr_typeA(JMP, 2);

    display_prog();
}

void load_prog2()
{
    for (int i = 0; i < PROG_MEM_SIZE; i++)
    { /* Initialize program memory */
        instr[i] = (char)0;
    }

    instr[0] = instr_typeB(SET, R1, 0);
    instr[1] = instr_typeB(SET, R0, 2);
    instr[2] = instr_typeA(JZ, 0);
    instr[3] = instr_typeA(CALL, 7);
    instr[4] = instr_typeA(CALL, 7);
    instr[5] = instr_typeB(DEC, R0, 1);
    instr[6] = instr_typeA(JMP, 2);
    instr[7] = instr_typeC(ADD, R1, R1, R0);
    instr[8] = instr_typeA(RET, 0);

    display_prog();
}