#pragma force_active on
extern "C" {
void* fn_27_1A1CFC(void*, short);
void* fn_91_5064(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_50DC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<unsigned char*>(object) + 0x524, static_cast<short>(-1));
        if (object != 0) fn_91_5064(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
