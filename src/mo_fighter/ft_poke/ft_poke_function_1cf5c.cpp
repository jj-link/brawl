#pragma force_active on
extern "C" {
void* fn_116_1CFE0(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_1D1AC(void*, short);

void* fn_116_1CF5C(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_116_1CFE0(owner + 0xf418, memberDeleting);
        fn_27_C74E8(owner + 0xf408, memberDeleting);
        fn_116_1D1AC(owner, 0);
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
