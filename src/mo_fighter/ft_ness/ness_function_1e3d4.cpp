#pragma force_active on
extern "C" {
void* fn_27_1A220C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_1E3D4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A220C(static_cast<char*>(object) + 0x10, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
