#pragma force_active on

extern "C" {
void* fn_110_2268(void*, short);
void* fn_110_2304(void*, short);
void* fn_110_2344(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_110_2724(void* object, short deleting) {
    if (object != 0) {
        fn_110_2268(static_cast<unsigned char*>(object) + 0xDC, -1);
        fn_110_2304(static_cast<unsigned char*>(object) + 0xC0, -1);
        fn_110_2344(static_cast<unsigned char*>(object) + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
