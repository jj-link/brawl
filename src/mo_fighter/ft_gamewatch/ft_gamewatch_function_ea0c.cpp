#pragma force_active on
extern "C" void fn_107_E9AC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_EA0C(void* object, short deleting) {
    if (object != 0) {
        fn_107_E9AC(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
