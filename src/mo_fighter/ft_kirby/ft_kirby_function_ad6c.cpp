#pragma force_active on
extern "C" {
void* fn_96_23A8(void*, short);
void* fn_96_2024(void*, short);
void* fn_96_1E98(void*, short);
void* fn_96_ACE8(void*, short);
void* fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_96_AD6C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_96_23A8(object + 0x1B5D0, memberDeleting);
        fn_96_2024(object + 0x1B118, memberDeleting);
        fn_96_1E98(object + 0x1B0DC, memberDeleting);
        fn_96_ACE8(object + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
