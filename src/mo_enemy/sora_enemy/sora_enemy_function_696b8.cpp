#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_6964C(void*, short);

extern "C" void* fn_41_696B8(void* p, short del) {
    if (p) {
        fn_41_69BF0((char*)p + 0x188, -1);
        fn_41_6964C((char*)p + 4, -1);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
