#include <new>

extern "C" {
void* fn_98_38F0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_98_3AEC(void*, short);
void* fn_98_2138(void*, short);
void* fn_98_21D4(void*, short);
void* fn_98_2214(void*, short);
void* fn_27_C7770(void*, short);
void* fn_98_3BB4(void*, short);
void* fn_98_3C10(void*, short);
void* fn_98_3C6C(void*, short);
void* fn_98_1B0C4(void*, short);
void* fn_98_3FAC(void*, short);
void* fn_98_1B124(void*, short);
void* fn_98_43F8(void*, short);
void* fn_98_452C(void*, short);
void* fn_98_5384(void*, short);
void* fn_98_4588(void*, short);
void* fn_98_45E4(void*, short);
void* fn_98_4650(void*, short);
void* fn_98_46B0(void*, short);
void* fn_98_4710(void*, short);
void* fn_98_4E20(void*, short);
void* fn_98_476C(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4900(void*, short);
void* fn_98_1B21C(void*, short);
void* fn_98_4A74(void*, short);
void* fn_98_4AE0(void*, short);
void* fn_98_4B98(void*, short);
void* fn_98_4BD8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_98_4C34(void*, short);
void* fn_98_1AC14(char*, short);
void* fn_98_1AC84(char*, short);
void* fn_98_1AD14(char*, short);
void* fn_98_1ADA0(char*, short);
void* fn_98_1AE2C(char*, short);
void* fn_98_1AEB8(char*, short);
void* fn_98_1AF44(char*, short);
}

extern "C" void* fn_98_1AB8C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_38F0(object + 0x1f34, memberDeleting);
        fn_27_1DBB60(object + 0x1efc, memberDeleting);
        fn_98_1AC14(object + 0xcc, memberDeleting);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

extern "C" void* fn_98_1AC14(char* object, short deleting) {
    if (object) {
        fn_98_1AC84(object + 0x1880, short(-1));
        fn_98_1AF44(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}

extern "C" void* fn_98_1AC84(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_3AEC(object + 0x4b0, memberDeleting);
        fn_98_1AD14(object + 0x384, memberDeleting);
        fn_98_1ADA0(object + 0x258, memberDeleting);
        fn_98_1AE2C(object + 0x12c, memberDeleting);
        fn_98_1AEB8(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

static inline void destroyCommonBase(char* object, short deleting) {
    if (object) fn_27_C7770(object, deleting);
}

// These four independently exported instantiations have the same member layout.
extern "C" void* fn_98_1AD14(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_2138(object + 0xdc, memberDeleting);
        fn_98_21D4(object + 0xc0, memberDeleting);
        fn_98_2214(object + 0x14, memberDeleting);
        destroyCommonBase(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
extern "C" void* fn_98_1ADA0(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_2138(object + 0xdc, memberDeleting);
        fn_98_21D4(object + 0xc0, memberDeleting);
        fn_98_2214(object + 0x14, memberDeleting);
        destroyCommonBase(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
extern "C" void* fn_98_1AE2C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_2138(object + 0xdc, memberDeleting);
        fn_98_21D4(object + 0xc0, memberDeleting);
        fn_98_2214(object + 0x14, memberDeleting);
        destroyCommonBase(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
extern "C" void* fn_98_1AEB8(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_2138(object + 0xdc, memberDeleting);
        fn_98_21D4(object + 0xc0, memberDeleting);
        fn_98_2214(object + 0x14, memberDeleting);
        destroyCommonBase(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}

extern "C" void* fn_98_1AF44(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_3BB4(object + 0x183c, memberDeleting);
        fn_98_3C10(object + 0x1824, memberDeleting);
        fn_98_3C6C(object + 0x1688, memberDeleting);
        fn_98_1B0C4(object + 0x1624, memberDeleting);
        fn_98_3FAC(object + 0x1570, memberDeleting);
        fn_98_1B124(object + 0x13a8, memberDeleting);
        fn_98_43F8(object + 0x1304, memberDeleting);
        fn_98_452C(object + 0x12d0, memberDeleting);
        fn_98_5384(object + 0x125c, memberDeleting);
        fn_98_4588(object + 0x1244, memberDeleting);
        fn_98_45E4(object + 0x10e0, memberDeleting);
        fn_98_4650(object + 0x1078, memberDeleting);
        fn_98_46B0(object + 0x106c, memberDeleting);
        fn_98_4710(object + 0x1044, memberDeleting);
        fn_98_4E20(object + 0xe74, memberDeleting);
        fn_98_476C(object + 0xe10, memberDeleting);
        fn_98_4838(object + 0xdd4, memberDeleting);
        fn_98_4900(object + 0xd1c, memberDeleting);
        fn_98_1B21C(object + 0xb10, memberDeleting);
        fn_98_4A74(object + 0x930, memberDeleting);
        fn_98_4AE0(object + 0x900, memberDeleting);
        fn_98_4B98(object + 0x8f0, memberDeleting);
        fn_98_4BD8(object + 0x8d8, memberDeleting);
        __dt__16soModuleAccesserFv(object + 0x7f8, memberDeleting);
        fn_98_4C34(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
