#pragma force_active on
extern "C" void fn_122_1AD0(void* self, short arg);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1B90(void* p, short flag) {
    if (p) {
        short z = 0;
        fn_122_1AD0(p, z);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
