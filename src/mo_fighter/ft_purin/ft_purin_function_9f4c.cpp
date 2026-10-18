#pragma force_active on
extern "C" void fn_124_9EF0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9F4C(void* p, int shouldDelete) {
    if (p != 0) {
        fn_124_9EF0((char*)p + 4, -1);
        if ((short)shouldDelete > 0)
            __dl__FPv(p);
    }
    return p;
}
