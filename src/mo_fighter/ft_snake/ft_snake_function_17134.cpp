#pragma force_active on
extern "C" void* fn_122_2158(void* p, short del);
extern "C" void* fn_122_21F4(void* p, short n);
extern "C" void* fn_122_2234(void* p, short flag);
extern "C" void* fn_27_C7770(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_122_17134(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short del = -1;
        fn_122_2158(members + 0xdc, del);
        fn_122_21F4(members + 0xc0, del);
        fn_122_2234(members + 0x14, del);
        if (object != 0) {
            fn_27_C7770(object, del);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
