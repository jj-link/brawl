#pragma force_active on
extern "C" void fn_125_48BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_5140(void* object, short deleting) {
    if (object != 0) {
        fn_125_48BC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
