#pragma force_active on
extern "C" void* fn_110_34FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_349C(void* object, short deleting) {
    if (object != 0) {
        fn_110_34FC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
