#pragma force_active on

extern "C" void fn_27_24ADF4(void*);
extern char* lbl_27_bss_5668;
extern char* g_GameGlobal;

extern "C" void fn_27_2529AC(char* self) {
    fn_27_24ADF4(self);
    *(int*)(self + 0x25c) = 0;
    *(int*)(self + 0x260) = 0;
    *(int*)(self + 0x264) = 0;
    *(int*)(self + 0x268) = 0;
    *(int*)(self + 0x26c) = 0;
    char* obj = lbl_27_bss_5668;
    if (obj && *(int*)(obj + 0x44) == 0x38) {
        unsigned int mode = *(unsigned int*)(obj + 0x354);
        int time = *(int*)(self + 0xe0);
        *(unsigned int*)(self + 0x268) = mode;
        *(int*)(self + 0x26c) = *(int*)(obj + 0x350);
        *(int*)(self + 0x264) = time;
        *(int*)(self + 0x25c) = (int)*(float*)(obj + 0x390);
        if (mode == 10) {
            *(int*)(self + 0x260) = time / 60;
        }
    }
    if ((((unsigned int)*(unsigned char*)(*(char**)(self + 0x44) + 8) >> 2) & 0x3f) == 3) {
        char* data = *(char**)(g_GameGlobal + 0x18);
        int* cursor = (int*)self;
        int i = 0;
        while (i < *(int*)(self + 0x270)) {
            int index = cursor[0x274 / 4];
            ++cursor;
            ++i;
            char* dest = data + *(unsigned char*)(*(char**)(self + 0x44) + index * 0x5c + 0x9b) * 0x2ac;
            *(int*)(dest + 0x264) = *(int*)(self + 0x260);
            *(int*)(dest + 0x268) = *(int*)(self + 0x25c);
            *(int*)(dest + 0x26c) = *(int*)(self + 0x268);
            *(int*)(dest + 0x270) = *(int*)(self + 0x264);
        }
    }
}
