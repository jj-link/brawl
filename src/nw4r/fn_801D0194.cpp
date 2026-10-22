#pragma force_active on
extern "C" void fn_801CFA14(void);
extern "C" void fn_801D0130(void);
extern "C" void OSJoinThread(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801D0194(void* p, int flag) {
    if (p != 0) {
        unsigned char* uc = (unsigned char*)p;
        if (uc[0x31D] != 0 && uc[0x31D] != 0) {
            uc[0x31C] = 1;
            fn_801CFA14();
            fn_801D0130();
            OSJoinThread(p, 0);
            uc[0x31D] = 0;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
