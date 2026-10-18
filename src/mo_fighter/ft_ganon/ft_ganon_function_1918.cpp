#pragma force_active on
extern "C" {
void* fn_109_19B8(void*, short);
void* fn_109_1D98(void*, short);
void* fn_109_1E34(void*, short);
void* fn_109_1F6C(void*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_109_1918(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_109_19B8((char*)object + 0xC8EC, memberDeleting);
        fn_109_1D98((char*)object + 0xC434, memberDeleting);
        fn_109_1E34((char*)object + 0xC3F8, memberDeleting);
        fn_109_1F6C((char*)object + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
