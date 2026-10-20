#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_94_13FFC(void*, short);
void* fn_27_CDBBC(void*, short);
void* fn_27_D36DC(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_94_13F74(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x118B0, static_cast<short>(-1));
        fn_94_13FFC(static_cast<unsigned char*>(object) + 0xe0, static_cast<short>(-1));
        fn_27_CDBBC(static_cast<unsigned char*>(object) + 0x34, static_cast<short>(-1));
        fn_27_D36DC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
