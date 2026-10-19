#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_CBB00(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F87C(void* object, short destroy) {
    if (object != 0) {
        fn_27_6A3D8(static_cast<unsigned char*>(object) + 0x110, -1);
        fn_27_CBB00(object, -1);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
