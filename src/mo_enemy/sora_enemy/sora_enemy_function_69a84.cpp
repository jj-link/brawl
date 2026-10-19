#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69A18(void*, short);

extern "C" void* fn_41_69A84(void* p, short flag) {
    if (p != 0) {
        fn_41_69BF0((char*)p + 0x338, -1);
        fn_41_69A18((char*)p + 4, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
