#pragma force_active on
extern "C" void* fn_119_AF08(void*, short);
extern "C" void* fn_119_ADD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_AF68(void* object, short deleting) {
    if (object != 0) {
        fn_119_AF08(static_cast<char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_119_ADD0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
