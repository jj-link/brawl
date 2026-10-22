#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern "C" {
    extern u8 lbl_805A0568;
    extern int lbl_804C1C8C[11];
    extern u8 lbl_804C1C80[0xC];
    void fn_801BB22C(void*, int);
    void __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_801BB188(void) {
    if ((s8)lbl_805A0568 == 0) {
        int* base = lbl_804C1C8C;
        int* r7;
        int* r8;
        int* r9;
        base[1] = 0;
        r9 = &base[1];
        r8 = (int*)((char*)base + 0x10);
        r7 = (int*)((char*)base + 0x1C);
        base[2] = 0;
        base[4] = 0;
        base[5] = 0;
        base[7] = 0;
        base[8] = 0;
        base[0] = 0;
        base[1] = (int)r9;
        base[2] = (int)r9;
        base[3] = 0;
        base[4] = (int)r8;
        base[5] = (int)r8;
        base[6] = 0;
        base[7] = (int)r7;
        base[8] = (int)r7;
        *(u8*)&base[9] = 0;
        __register_global_object(base, (void*)fn_801BB22C, lbl_804C1C80);
        lbl_805A0568 = 1;
    }
    return lbl_804C1C8C;
}
