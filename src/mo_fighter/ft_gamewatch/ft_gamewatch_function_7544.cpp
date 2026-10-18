#pragma force_active on
extern "C" void fn_107_3C8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_7544(void* object, short deleting) {
    if (object != 0) {
        fn_107_3C8C(static_cast<char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
