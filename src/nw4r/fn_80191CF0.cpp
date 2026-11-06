#pragma force_active on
#pragma peephole off

extern "C" void fn_801F4EAC(unsigned int, unsigned int);

extern "C" void fn_80191CF0(unsigned int* p, unsigned int n, int flag) {
    if (n == 0) {
        return;
    }

    unsigned int value = *p;
    if (flag != 0) {
        if (n < 2) {
            fn_801F4EAC(value, 0x20);
        } else if (n < 4) {
            fn_801F4EAC(value, 0x40);
        } else if (n < 8) {
            fn_801F4EAC(value, 0x80);
        } else {
            fn_801F4EAC(value, 0xA0);
        }
        return;
    }

    if (n < 2) {
        *(unsigned char*)0xCC008000 = 0x40;
        *(unsigned int*)0xCC008000 = value;
        *(unsigned int*)0xCC008000 = 0x20;
    } else if (n < 4) {
        *(unsigned char*)0xCC008000 = 0x40;
        *(unsigned int*)0xCC008000 = value;
        *(unsigned int*)0xCC008000 = 0x40;
    } else if (n < 8) {
        *(unsigned char*)0xCC008000 = 0x40;
        *(unsigned int*)0xCC008000 = value;
        *(unsigned int*)0xCC008000 = 0x80;
    } else {
        *(unsigned char*)0xCC008000 = 0x40;
        *(unsigned int*)0xCC008000 = value;
        *(unsigned int*)0xCC008000 = 0xA0;
    }
}
