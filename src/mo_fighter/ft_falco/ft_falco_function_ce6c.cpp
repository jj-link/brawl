#pragma force_active on
extern "C" void* fn_108_CE0C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_CE6C(void* object, short deleting) {
    if (object != 0) {
        fn_108_CE0C(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
