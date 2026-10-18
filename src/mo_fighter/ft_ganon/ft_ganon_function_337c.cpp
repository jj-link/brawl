#pragma force_active on
extern "C" void* fn_109_33DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_337C(void* object, short deleting) {
    if (object != 0) {
        fn_109_33DC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
