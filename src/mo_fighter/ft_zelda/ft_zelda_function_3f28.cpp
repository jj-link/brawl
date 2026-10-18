#pragma force_active on
extern "C" void fn_104_1F30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_3F28(void* object, short deleting) {
    if (object != 0) {
        fn_104_1F30(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
