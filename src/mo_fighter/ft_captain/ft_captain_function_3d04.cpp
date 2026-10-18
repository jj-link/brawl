#pragma force_active on
extern "C" void fn_27_1A2B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3D04(void* object, short flag) {
    if (object != 0) {
        fn_27_1A2B08(static_cast<unsigned char*>(object) + 4, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
