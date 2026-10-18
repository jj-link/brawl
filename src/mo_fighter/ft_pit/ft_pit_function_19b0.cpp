#pragma force_active on
extern "C" {
void fn_112_1A50(char*, short);
void fn_112_1E30(char*, short);
void fn_112_1ECC(char*, short);
void fn_112_2004(char*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_112_19B0(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_112_1A50(object + 0x296F4, memberDeleting);
        fn_112_1E30(object + 0x2923C, memberDeleting);
        fn_112_1ECC(object + 0x29200, memberDeleting);
        fn_112_2004(object + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
