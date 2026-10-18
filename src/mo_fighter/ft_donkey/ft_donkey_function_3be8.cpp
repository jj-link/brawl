#pragma force_active on
extern "C" void fn_92_3C48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3BE8(void* object, short deleting) {
    if (object != 0) {
        fn_92_3C48(static_cast<char*>(object) + 0x38, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
