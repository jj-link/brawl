#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void fn_122_4AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_5BC8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* base = static_cast<unsigned char*>(object);
        fn_27_13C90(base + 0x9C, -1);
        fn_27_21038(base + 0x88, -1);
        fn_122_4AD0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
