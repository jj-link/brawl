#pragma force_active on
extern "C" void* fn_27_B5324(void* p, short flag);
extern "C" void* fn_106_4A44(void* p, short flag);
extern "C" void* fn_106_4AA0(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_106_49CC(void* p, short flag) {
    if (p != 0) {
        short neg = -1;
        fn_27_B5324((char*)p + 0x30, neg);
        fn_106_4A44((char*)p + 0x18, neg);
        fn_106_4AA0((char*)p + 0x4, neg);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
