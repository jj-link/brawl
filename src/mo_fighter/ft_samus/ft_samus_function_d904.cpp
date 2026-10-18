#pragma force_active on
extern "C" void fn_94_D8A8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D904(void* object, short deleting) {
    if (object != 0) {
        fn_94_D8A8(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
