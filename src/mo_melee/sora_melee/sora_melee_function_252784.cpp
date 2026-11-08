#pragma force_active on
extern "C" void* g_IfMngr;
extern "C" char* lbl_27_bss_5668;
extern "C" void fn_800DCDDC(void*, void*, int);
struct Self { char pad[0x26c]; int value; };
struct Entry { int a; char b; char pad[3]; };
extern "C" void fn_27_252784(Self* self) {
    Entry buf[11];
    if (g_IfMngr) {
        int count = 0;
        char* p = lbl_27_bss_5668;
        if (p && *(int*)(p + 0x44) == 0x38)
            count = *(int*)(p + 0x358);
        for (int i = 0; i < count; ++i) {
            buf[i].a = 0x2c;
            buf[i].b = self->value;
        }
        fn_800DCDDC(g_IfMngr, buf, count);
    }
}