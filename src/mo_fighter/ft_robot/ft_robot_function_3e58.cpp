#pragma force_active on
extern "C" void* fn_120_3EB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_3E58(void* object, short deleting) {
    if (object != 0) {
        fn_120_3EB8(static_cast<char*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
