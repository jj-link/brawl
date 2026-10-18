#pragma force_active on
extern "C" {
void* fn_101_F440(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_F4A0(void* object, short deleting) {
    if (object != 0) {
        fn_101_F440(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
