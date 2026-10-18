#pragma force_active on
extern "C" void fn_92_B188(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_B1E8(void* object, short deleting) {
    if (object != 0) {
        fn_92_B188(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
