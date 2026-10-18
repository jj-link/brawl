#pragma force_active on
extern "C" void* fn_104_3DB0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_1850C(void* object, short deleting) {
    if (object != 0) {
        fn_104_3DB0(static_cast<char*>(object) + 0x14, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
