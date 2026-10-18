#pragma force_active on
extern "C" void fn_107_5330(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_52D0(void* object, short deleting) {
    if (object != 0) {
        fn_107_5330(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
