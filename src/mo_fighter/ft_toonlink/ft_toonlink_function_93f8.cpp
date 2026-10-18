#pragma force_active on
extern "C" {
void* fn_121_1E9C(void*, short);
void* fn_121_1B18(void*, short);
void* fn_121_198C(void*, short);
void* fn_121_9374(void*, short);
void* fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_121_93F8(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_121_1E9C(owner + 0x1A2DC, memberDeleting);
        fn_121_1B18(owner + 0x19E24, memberDeleting);
        fn_121_198C(owner + 0x19DE8, memberDeleting);
        fn_121_9374(owner + 0x194, memberDeleting);
        fn_27_125E20(owner, short(0));
        if (deleting > 0) __dl__FPv(owner);
    }
    return owner;
}
}
