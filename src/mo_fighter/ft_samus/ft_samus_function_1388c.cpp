#pragma force_active on
extern "C" void* fn_94_2158(void*, short);
extern "C" void* fn_94_21F4(void*, short);
extern "C" void* fn_94_2234(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1388C(void* object, short deleting) {
    if (object != 0) {
        short minusOne = -1;
        fn_94_2158(static_cast<unsigned char*>(object) + 0xdc, minusOne);
        fn_94_21F4(static_cast<unsigned char*>(object) + 0xc0, minusOne);
        fn_94_2234(static_cast<unsigned char*>(object) + 0x14, minusOne);
        if (object != 0) {
            fn_27_C7770(object, minusOne);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
