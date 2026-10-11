#include <new>

extern "C" {
void* fn_98_398C(void*, short);
void* fn_98_171B4(char*, short);
void* fn_98_3B58(void*, short);
void* fn_98_3BB4(void*, short);
void* fn_98_3C10(void*, short);
void* fn_98_3C6C(void*, short);
void* fn_98_17350(void*, short);
void* fn_98_1770C(void*, short);
void* fn_98_3FAC(void*, short);
void* fn_98_40E8(void*, short);
void* fn_98_43F8(void*, short);
void* fn_98_452C(void*, short);
void* fn_98_4588(void*, short);
void* fn_98_45E4(void*, short);
void* fn_98_4650(void*, short);
void* fn_98_46B0(void*, short);
void* fn_98_4710(void*, short);
void* fn_98_4E20(void*, short);
void* fn_98_476C(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4900(void*, short);
void* fn_98_4974(void*, short);
void* fn_98_4A74(void*, short);
void* fn_98_4AE0(void*, short);
void* fn_98_4B98(void*, short);
void* fn_98_4BD8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_98_4C34(void*, short);

void* fn_98_17140(char* storage, short deleting) {
    if (storage) {
        fn_98_398C(storage + 0x9f04, short(-1));
        fn_98_171B4(storage, short(0));
        if (deleting > 0) operator delete(storage);
    }
    return storage;
}

void* fn_98_171B4(char* storage, short deleting) {
    if (storage) {
        short memberDeleting = -1;
        fn_98_3B58(storage + 0x9ee8, memberDeleting);
        fn_98_3BB4(storage + 0x9ea8, memberDeleting);
        fn_98_3C10(storage + 0x9e90, memberDeleting);
        fn_98_3C6C(storage + 0x9cf4, memberDeleting);
        fn_98_17350(storage + 0x161c, memberDeleting);
        fn_98_1770C(storage + 0x15a8, memberDeleting);
        fn_98_3FAC(storage + 0x14f4, memberDeleting);
        fn_98_40E8(storage + 0x1334, memberDeleting);
        fn_98_43F8(storage + 0x1290, memberDeleting);
        fn_98_452C(storage + 0x125c, memberDeleting);
        fn_98_4588(storage + 0x1244, memberDeleting);
        fn_98_45E4(storage + 0x10e0, memberDeleting);
        fn_98_4650(storage + 0x1078, memberDeleting);
        fn_98_46B0(storage + 0x106c, memberDeleting);
        fn_98_4710(storage + 0x1044, memberDeleting);
        fn_98_4E20(storage + 0xe74, memberDeleting);
        fn_98_476C(storage + 0xe10, memberDeleting);
        fn_98_4838(storage + 0xdd4, memberDeleting);
        fn_98_4900(storage + 0xd1c, memberDeleting);
        fn_98_4974(storage + 0xb10, memberDeleting);
        fn_98_4A74(storage + 0x930, memberDeleting);
        fn_98_4AE0(storage + 0x900, memberDeleting);
        fn_98_4B98(storage + 0x8f0, memberDeleting);
        fn_98_4BD8(storage + 0x8d8, memberDeleting);
        __dt__16soModuleAccesserFv(storage + 0x7f8, memberDeleting);
        fn_98_4C34(storage, memberDeleting);
        if (deleting > 0) operator delete(storage);
    }
    return storage;
}
}
