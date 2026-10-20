#pragma force_active on
extern "C" void* fn_93_62F8(void*, short);
extern "C" void* fn_93_62B8(void*, short);
extern "C" void* fn_93_6394(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_8C88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_93_62F8(members + 0xDC, -1);
        fn_93_62B8(members + 0xC0, -1);
        fn_93_6394(members + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
