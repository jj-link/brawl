#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_CBB00(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_11DA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_6A3D8(storage + 0x110, -1);
        fn_27_CBB00(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
