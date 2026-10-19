#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5EB48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5EBB4(void* object, short shouldDelete) {
    if (object != 0) {
        fn_41_5EE64(static_cast<char*>(object) + 0x188, -1);
        fn_41_5EB48(static_cast<char*>(object) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
