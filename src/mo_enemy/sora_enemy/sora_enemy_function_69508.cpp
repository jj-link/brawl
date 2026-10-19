#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_6949C(void*, short);

extern "C" char* fn_41_69508(char* p1, short p2) {
    if (p1 != 0) {
        short m = -1;
        fn_41_69BF0(p1 + 0xc8, m);
        fn_41_6949C(p1 + 4, m);
        if (p2 > 0) {
            delete p1;
        }
    }
    return p1;
}
