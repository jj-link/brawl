#pragma force_active on
extern "C" void fn_94_14E8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_15608(void* object, short deleting) {
    if (object != 0) {
        fn_94_14E8C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
