#pragma force_active on
extern "C" void* fn_41_27D8(void* object, short shouldDelete);
extern "C" void* fn_41_2890(void* p, short flag);
extern "C" void* fn_41_2FF44(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_30018(void* p, short flag) {
    if (p != 0) {
        short neg = -1;
        fn_41_27D8((char*)p + 0xcc, neg);
        fn_41_2890((char*)p + 0xb0, neg);
        fn_41_2FF44((char*)p + 0x4, neg);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
