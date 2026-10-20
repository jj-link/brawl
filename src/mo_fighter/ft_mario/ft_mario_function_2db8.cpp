#pragma force_active on
extern "C" {
void* fn_91_2C9C(void*, short);
void* fn_91_2D5C(void*, short);
void* fn_27_CD934(void*, short);

#pragma dont_inline on
void* fn_91_2DB8(void* object, short deleting) {
    if (object != 0) {
        fn_91_2C9C(static_cast<unsigned char*>(object) + 0xac, static_cast<short>(-1));
        fn_91_2D5C(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(-1));
        fn_27_CD934(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
