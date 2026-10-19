#pragma force_active on
extern "C" void fn_41_5D12C(void*, short);
extern "C" void fn_41_5CFC0(void*, short);

extern "C" void* fn_41_5D02C(void* p, short flag) {
    if (p != 0) {
        fn_41_5D12C((char*)p + 0x98, -1);
        fn_41_5CFC0((char*)p + 4, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
