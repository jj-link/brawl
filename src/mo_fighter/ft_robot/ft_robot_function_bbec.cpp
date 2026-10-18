#pragma force_active on
extern "C" void fn_120_BB90(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_BBEC(void* object, short deleting) {
    if (object != 0) {
        fn_120_BB90(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
