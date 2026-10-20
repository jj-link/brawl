#pragma force_active on
extern "C" void* fn_124_9AEC(void*, short);
extern "C" void fn_124_99B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9B4C(void* p, short flag) {
    if (p != 0) {
        fn_124_9AEC((char*)p + 0xec, -1);
        if (p != 0) {
            fn_124_99B4(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
