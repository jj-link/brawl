#pragma force_active on
extern "C" void fn_124_95E4(void* p, short flag);

extern "C" void* fn_124_96A4(void* p, short flag) {
    if (p) {
        if (p) {
            fn_124_95E4((char*)p + 4, -1);
        }
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
