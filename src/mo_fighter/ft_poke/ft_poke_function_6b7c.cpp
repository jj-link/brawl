#pragma force_active on
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_116_6C30(void*, short);
void* fn_27_21038(void*, short);
void* fn_116_6C9C(void*, short);
void* fn_116_6CF8(void*, short);
void* fn_116_6D54(void*, short);
void* fn_116_6DB0(void*, short);
void* fn_116_6E0C(void*, short);
}
void operator delete(void*);

extern "C" void* fn_116_6B7C(void* object, short deleting) {
    if (object != 0) {
        short minus_one = -1;
        fn_27_13C90((char*)object + 0x26c, minus_one);
        fn_116_6C30((char*)object + 0x230, minus_one);
        fn_27_21038((char*)object + 0x220, minus_one);
        fn_116_6C9C((char*)object + 0x200, minus_one);
        fn_116_6CF8((char*)object + 0x1e0, minus_one);
        fn_116_6D54((char*)object + 0x1a8, minus_one);
        fn_116_6DB0((char*)object + 0xc4, minus_one);
        fn_116_6E0C(object, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
