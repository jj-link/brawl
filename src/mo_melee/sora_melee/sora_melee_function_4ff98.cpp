#pragma force_active on
extern "C" void fn_8015BF9C(void*, int);

extern "C" void fn_27_4FF98(char* self) {
    int i = 0;
    char* p = self + 0x40;
    do {
        fn_8015BF9C(p, 0x18);
        i++;
        p += 0xc;
    } while (i < 7);
}
