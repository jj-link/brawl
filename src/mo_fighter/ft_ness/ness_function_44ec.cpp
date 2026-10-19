#pragma force_active on
extern "C" {
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_44EC(void* object, short deleting) {
    if (object != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x110,
                    static_cast<short>(-1));
        fn_27_CBB00(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
