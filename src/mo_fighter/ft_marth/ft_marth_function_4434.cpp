#pragma force_active on

extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_106_44A0(void* p, short flags);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4434(void* p, short flag) {
    if (p) {
        fn_27_565F0(static_cast<unsigned char*>(p) + 0x14, -1);
        fn_106_44A0(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
