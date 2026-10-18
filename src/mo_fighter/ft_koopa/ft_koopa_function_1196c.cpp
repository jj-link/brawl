#pragma force_active on
extern "C" void fn_102_119CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1196C(void* object, short deleting) {
    if (object != 0) {
        fn_102_119CC(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
