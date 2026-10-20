#pragma force_active on
extern "C" void* fn_92_3F8C(void*, short);
extern "C" void* fn_92_52E8(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_5270(void* object, short deleting) {
    if (object != 0) {
        fn_92_3F8C(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_92_52E8(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
