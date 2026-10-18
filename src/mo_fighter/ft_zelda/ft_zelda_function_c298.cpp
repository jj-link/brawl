#pragma force_active on
extern "C" void* fn_104_C23C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C298(void* object, short deleting) {
    if (object != 0) {
        fn_104_C23C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
