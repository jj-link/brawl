#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void* fn_41_69364(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_693C4(void* p1, short p2) {
    short count = -1;
    if (p1) {
        fn_41_69BF0((char*)p1 + 0x38, count);
        fn_41_69364((char*)p1 + 4, count);
        if (p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}
