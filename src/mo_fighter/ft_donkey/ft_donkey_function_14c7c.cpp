#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_92_459C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_14C7C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = (unsigned char*)object;
        fn_27_13C90(p + 0x9C, -1);
        fn_27_21038(p + 0x88, -1);
        fn_92_459C(object, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
