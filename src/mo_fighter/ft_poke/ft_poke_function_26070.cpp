#pragma force_active on
extern "C" void* fn_116_4B64(void*, short);
extern "C" void* fn_116_260E8(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_26070(void* object, short deleting) {
    if (object != 0) {
        fn_116_4B64(static_cast<unsigned char*>(object) + 0x6C, -1);
        fn_116_260E8(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
