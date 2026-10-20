#pragma force_active on
extern "C" {
void* fn_27_1F9CC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_110_1E37C(void* owner, short deleting);
void __dl__FPv(void*);

void* fn_110_1FAE4(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_27_1F9CC(owner + 0xB250, memberDeleting);
        fn_27_C74E8(owner + 0xB23C, memberDeleting);
        fn_110_1E37C(owner, 0);
        if (deleting > 0) __dl__FPv(owner);
    }
    return owner;
}
}
