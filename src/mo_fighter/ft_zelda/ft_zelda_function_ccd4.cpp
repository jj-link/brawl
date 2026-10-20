#pragma force_active on
extern "C" void* fn_104_CC74(void*, short);
extern "C" void* fn_104_CB40(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_CCD4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = (unsigned char*)object;
        fn_104_CC74(p + 0x204, -1);
        if (object != 0) fn_104_CB40(object, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
