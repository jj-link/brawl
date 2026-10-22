#pragma force_active on
extern "C" void fn_8010CA20(void*, int);
extern "C" void fn_8010CA94(void*, int, void*);

extern "C" int fn_80107914(unsigned char* self, int val) {
    void* p = *(void**)(self + 0x104);
    if (p == 0) {
        return 0;
    }
    if (p != 0) {
        fn_8010CA20(p, 1);
    }
    int n = *(int*)(self + 0xE0) + 1;
    *(int*)(self + 0xE0) = n;
    if (n >= 0x63) {
        return 0;
    }
    unsigned char* q = self + n;
    q[0x7C] = (unsigned char)val;
    p = *(void**)(self + 0x104);
    if (p != 0) {
        ((unsigned char*)p)[0x360] = 1;
    }
    p = *(void**)(self + 0x104);
    if (p != 0) {
        fn_8010CA94(p, *(int*)(self + 0xE0), self + 0x7C);
    }
    return 1;
}
