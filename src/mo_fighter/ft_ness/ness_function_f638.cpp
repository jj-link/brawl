#pragma force_active on
extern "C" {
void* fn_101_F5D8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_101_F638(void* object, short deleting) {
    if (object != 0) {
        fn_101_F5D8(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
