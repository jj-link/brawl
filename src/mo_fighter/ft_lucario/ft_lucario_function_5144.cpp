#pragma force_active on
extern "C" void* fn_118_3EB4(void*, short);
extern "C" void* fn_118_51BC(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_5144(void* object, short deleting) {
    if (object != 0) {
        fn_118_3EB4(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_118_51BC(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
