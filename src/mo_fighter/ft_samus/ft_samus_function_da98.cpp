#pragma force_active on
extern "C" void fn_94_DA3C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_DA98(void* object, short deleting) {
    if (object != 0) {
        fn_94_DA3C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
