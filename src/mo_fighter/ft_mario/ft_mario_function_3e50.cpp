#pragma force_active on
extern "C" {
void* fn_27_150488(void*, short);
void* fn_91_3DF4(void*, short);
void* fn_27_199A54(void*, short);

#pragma dont_inline on
void* fn_91_3E50(void* object, short deleting) {
    if (object != 0) {
        fn_27_150488(static_cast<unsigned char*>(object) + 0x5b8, static_cast<short>(-1));
        fn_91_3DF4(static_cast<unsigned char*>(object) + 0x584, static_cast<short>(-1));
        if (object != 0) fn_27_199A54(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
