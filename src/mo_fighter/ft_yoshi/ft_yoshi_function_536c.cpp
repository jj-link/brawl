#pragma force_active on
extern "C" void* fn_95_53CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_536C(void* object, short deleting) {
    if (object != 0) {
        fn_95_53CC(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
