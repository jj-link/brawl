#pragma force_active on
extern "C" void fn_800E2964(void* a, int* b, int c);
extern "C" void fn_800E2B00(void* p, void* a, int b);
extern "C" void fn_800E3378(void);
extern "C" void fn_800E3384(void* p);
extern void* g_IfMngr;

extern "C" void fn_800DD3EC(void) {
    char sp10[0x78];
    int sp8;
    int i;
    char* p;
    char* base = (char*)g_IfMngr;
    fn_800E2964(sp10, &sp8, 7);
    fn_800E3378();
    for (i = 0; i < 7; i++) {
        p = *(char**)(base + 0x4C);
        if (p != 0 && (((unsigned char)p[0] >> 5) & 1)) {
            fn_800E2B00(p, sp10, sp8);
            fn_800E3384(*(void**)(base + 0x4C));
        }
        base += 4;
    }
}
