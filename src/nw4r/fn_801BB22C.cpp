#pragma force_active on
extern "C" void fn_8015C238(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801BB22C(void* p, int flags) {
    if (p != 0) {
        void* a = (char*)p + 0x18;
        if (a != 0) {
            fn_8015C238(a, 0);
        }
        void* b = (char*)p + 0xC;
        if (b != 0) {
            fn_8015C238(b, 0);
        }
        if (p != 0) {
            fn_8015C238(p, 0);
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
