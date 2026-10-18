#pragma force_active on
extern "C" {
void fn_104_1A34(void*, short);
void fn_104_1E14(void*, short);
void fn_104_1EB0(void*, short);
void fn_104_1FE8(void*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_104_1994(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_104_1A34(owner + 0x185B8, memberDeleting);
        fn_104_1E14(owner + 0x18100, memberDeleting);
        fn_104_1EB0(owner + 0x180C4, memberDeleting);
        fn_104_1FE8(owner + 0x194, memberDeleting);
        fn_27_125E20(owner, short(0));
        if (deleting > 0) __dl__FPv(owner);
    }
    return owner;
}
}
