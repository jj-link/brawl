#pragma force_active on
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_95_3DA4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_62D0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_95_3DA4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
