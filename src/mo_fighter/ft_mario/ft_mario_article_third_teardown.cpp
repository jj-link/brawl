extern "C" {
void* fn_27_1D81C8(void*, short);
void* fn_91_189AC(void*, short);
void* fn_91_60C8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_91_6164(void*, short);
void* fn_91_18920(void*, short);
void* fn_91_622C(void*, short);
void* fn_91_62C8(void*, short);
void* fn_91_61D0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_91_1867C(void*, short);
void* fn_91_186EC(void*, short);
void* fn_91_1877C(void*, short);
void* fn_91_18808(void*, short);
void* fn_91_18894(void*, short);

#pragma dont_inline on
void* fn_91_185F4(void* object, int deleting) {
    if (object != 0) {
        fn_91_60C8(static_cast<unsigned char*>(object) + 0x1f44, static_cast<short>(-1));
        fn_27_1DBB60(static_cast<unsigned char*>(object) + 0x1f0c, static_cast<short>(-1));
        fn_91_1867C(static_cast<unsigned char*>(object) + 0xcc, static_cast<short>(-1));
        fn_27_1D81C8(object, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
void* fn_91_1867C(void* object, short deleting) {
    if (object != 0) {
        fn_91_186EC(static_cast<unsigned char*>(object) + 0x1890, static_cast<short>(-1));
        fn_91_189AC(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_186EC(void* object, short deleting) {
    if (object != 0) {
        fn_91_6164(static_cast<unsigned char*>(object) + 0x4b0, static_cast<short>(-1));
        fn_91_1877C(static_cast<unsigned char*>(object) + 0x384, static_cast<short>(-1));
        fn_91_18808(static_cast<unsigned char*>(object) + 0x258, static_cast<short>(-1));
        fn_91_18894(static_cast<unsigned char*>(object) + 0x12c, static_cast<short>(-1));
        fn_91_18920(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_1877C(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18808(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18894(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18920(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
