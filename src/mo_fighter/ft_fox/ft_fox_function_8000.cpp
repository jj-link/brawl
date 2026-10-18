#pragma force_active on
extern "C" void fn_27_1A7008(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_8000(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A7008(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
