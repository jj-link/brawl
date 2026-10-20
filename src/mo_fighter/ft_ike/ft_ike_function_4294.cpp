#pragma force_active on
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_119_430C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_4294(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0xB4, -1);
        if (object != 0) {
            fn_119_430C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
