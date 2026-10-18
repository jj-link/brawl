#pragma force_active on
extern "C" void fn_126_8004(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_8064(void* object, short deleting) {
    if (object != 0) {
        fn_126_8004(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
