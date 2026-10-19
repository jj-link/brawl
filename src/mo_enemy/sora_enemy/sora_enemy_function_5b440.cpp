#pragma force_active on
extern "C" void* fn_41_5B3DC(void* p1, short p2);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5B440(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_5B3DC((char*)p1 + 0x8, -1);
        fn_41_33D4C(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
