#pragma force_active on
extern "C" void fn_801BBC1C(void*, int*, int*);
extern "C" void fn_801BBC68(void*, int, int);
extern "C" void fn_80203980(void*);

extern "C" void fn_801C01D4(void* self) {
    unsigned char* p = (unsigned char*)self;
    int a, b;
    if (p[0xC]) {
        p[0xC] = 0;
        fn_801BBC1C(p + 0xC, &a, &b);
        fn_80203980(p + 0x24);
        fn_801BBC68(p + 0xC, a, b);
    }
}
