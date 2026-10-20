#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_91_4F74(void*, short);

#pragma dont_inline on
void* fn_91_4FEC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x48c, static_cast<short>(-1));
        if (object != 0) fn_91_4F74(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
