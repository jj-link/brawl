#pragma force_active on
extern "C" void* fn_124_9954(void*, short);
extern "C" void* fn_124_9824(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_99B4(void* p, int flag) {
    if (p != 0) {
        fn_124_9954((char*)p + 0x94, (short)-1);
        if (p != 0) {
            fn_124_9824(p, (short)0);
        }
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
