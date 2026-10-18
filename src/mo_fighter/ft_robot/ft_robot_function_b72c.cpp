#pragma force_active on
extern "C" void fn_120_B6D0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_B72C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_120_B6D0(members + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
