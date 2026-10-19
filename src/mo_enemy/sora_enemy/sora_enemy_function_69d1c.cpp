#pragma force_active on
extern "C" void fn_41_69C50(void*, short);

extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69D1C(void* p, short flag) {
    if (p != 0) {
        if (p != 0) {
            fn_41_69C50(static_cast<char*>(p) + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
