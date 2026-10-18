#pragma force_active on
extern "C" void* fn_120_3718(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_36B8(void* object, short deleting) {
    if (object != 0) {
        fn_120_3718(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
