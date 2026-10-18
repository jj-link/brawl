#pragma force_active on
extern "C" void fn_115_17D6C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_173D0(void* object, short deleting) {
    if (object != 0) {
        fn_115_17D6C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
