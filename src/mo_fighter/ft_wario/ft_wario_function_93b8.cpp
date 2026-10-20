#pragma force_active on
extern "C" {
void* fn_27_1F9CC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_110_1A2C(char* owner, short deleting);
void __dl__FPv(void*);

void* fn_110_93B8(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_27_1F9CC(owner + 0xD2FC, memberDeleting);
        fn_27_C74E8(owner + 0xD2E8, memberDeleting);
        fn_110_1A2C(owner, 0);
        if (deleting > 0) __dl__FPv(owner);
    }
    return owner;
}
}
