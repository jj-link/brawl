#pragma force_active on
extern "C" void fn_124_A218(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_89B8(void* p, short flag) {
    if (p != 0) {
        fn_124_A218((char*)p + 4, -1);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
