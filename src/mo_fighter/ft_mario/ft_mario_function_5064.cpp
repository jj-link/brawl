#pragma force_active on
extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_91_4FEC(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_5064(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x4b8, static_cast<short>(-1));
        if (object != 0) fn_91_4FEC(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
