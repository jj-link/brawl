#pragma force_active on
extern "C" void fn_27_27C580(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_85_52D4(void* p, int shouldDelete)
{
    if (p != 0) {
        fn_27_27C580(p, 0);
        if (shouldDelete > 0)
            __dl__FPv(p);
    }
    return p;
}
