#pragma force_active on
extern "C" void* fn_124_97C4(void*, short);
extern "C" void* fn_124_96A4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9824(void* p, short flag) {
    if (p != 0) {
        short dtor = -1;
        fn_124_97C4((char*)p + 0x60, dtor);
        fn_124_96A4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
