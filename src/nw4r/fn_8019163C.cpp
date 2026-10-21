#pragma force_active on
#pragma peephole off

extern "C" void fn_801F4EAC(unsigned int, unsigned int);

extern "C" void fn_8019163C(unsigned int* p, int n, int flag) {
    if (n == 0) {
        return;
    }

    unsigned int value = *p;
    if (flag != 0) {
        fn_801F4EAC(value, 0x40);
    } else {
        unsigned char* fifo = (unsigned char*)0xCC008000;
        *fifo = 0x40;
        *(unsigned int*)fifo = value;
        *(unsigned int*)fifo = 0x40;
    }
}
