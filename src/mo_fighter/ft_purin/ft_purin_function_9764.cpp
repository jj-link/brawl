#pragma force_active on
extern "C" void fn_124_9708(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9764(void* p, int flag) {
    if (p != 0) {
        fn_124_9708((char*)p + 4, -1);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
