#pragma force_active on
extern "C" void fn_124_9524(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9584(void* p, int shouldDelete) {
    if (p != 0) {
        fn_124_9524((char*)p + 4, -1);
        if ((short)shouldDelete > 0)
            __dl__FPv(p);
    }
    return p;
}
