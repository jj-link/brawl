#pragma force_active on
#pragma peephole off

extern "C" void fn_801F4EAC(int, int);

extern "C" void fn_80190AA8(int* p, int flag) {
    int value = *p;
    if (flag != 0) {
        fn_801F4EAC(value, 0x20);
        return;
    }
    *(unsigned char*)0xCC008000 = 0x40;
    *(int*)0xCC008000 = value;
    *(unsigned int*)0xCC008000 = 0x20;
}
