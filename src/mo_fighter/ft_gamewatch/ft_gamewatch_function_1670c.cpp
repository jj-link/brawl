#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_107_67C0(void* ptr, short size);

extern "C" void* fn_107_1670C(void* arg3, void* arg4) {
    if (arg3 != 0) {
        short zero = 0;
        fn_107_67C0(arg3, zero);
        short s = (short)arg4;
        if (s > 0) {
            __dl__FPv(arg3);
        }
    }
    return arg3;
}
