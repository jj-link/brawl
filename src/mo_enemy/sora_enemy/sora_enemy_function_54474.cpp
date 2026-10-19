#pragma force_active on
extern "C" void fn_41_543B4(void* p1, short p2);

extern "C" void* fn_41_54474(void* p1, short p2) {
    if (p1 != 0) {
        if (p1 != 0) {
            fn_41_543B4((char*)p1 + 4, -1);
        }
        if (p2 > 0) {
            operator delete(p1);
        }
    }
    return p1;
}
