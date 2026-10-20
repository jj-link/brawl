#pragma force_active on
extern "C" void fn_8015BF9C(void*, int);

extern "C" void fn_27_C172C(char* self) {
    int i = 0;
    char* p = self + 0x40;
    for (; i < 4; i++) {
        fn_8015BF9C(p, 0x20);
        p += 0xc;
    }
    i = 0;
    char* q = self + 0x70;
    for (; i < 4; i++) {
        fn_8015BF9C(q, 0x20);
        q += 0xc;
    }
    *(int*)(self + 0xa0) = 0;
}
