#pragma force_active on
extern "C" void* fn_80024A18(int, unsigned int);
extern "C" void fn_100_E184(float* destination, const float* source);
extern "C" void* lbl_100_bss_268;
extern "C" void* lbl_100_bss_2D0;
extern "C" float lbl_100_rodata_48;

struct EntryFlags {
    unsigned char a : 3;
    unsigned char b : 5;
};

struct CaptainEntry {
    int a;
    int b;
    int c;
    int d;
    int e;
    float vec[4];
    EntryFlags flags;
};

extern "C" void fn_100_F73C(void) {
    lbl_100_bss_268 = fn_80024A18(0x1F, 0x118);
    lbl_100_bss_2D0 = fn_80024A18(0x1F, 0x104);
    int i;
    CaptainEntry* p = (CaptainEntry*)lbl_100_bss_268;
    i = 0;
    while (i < 7) {
        p->a = -1;
        p->b = -1;
        p->d = -1;
        p->e = -1;
        float f[3];
        f[0] = lbl_100_rodata_48;
        f[1] = lbl_100_rodata_48;
        f[2] = lbl_100_rodata_48;
        fn_100_E184(p->vec, f);
        p->c = 0;
        p->flags.a = 0;
        ++i;
        ++p;
    }
}
