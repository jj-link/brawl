#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_116_20D8(void*, short);
void* fn_116_229C(void*, short);
void* fn_116_158B4(void*, short);
void* fn_116_15940(void*, short);
void* fn_116_159CC(void*, short);
void* fn_116_15A58(void*, short);
void* fn_116_15AE4(void*, short);
void* fn_116_15B70(void*, short);
void* fn_116_15BFC(void*, short);
void* fn_116_15C88(void*, short);
void* fn_116_15D14(void*, short);
}
extern "C" void* fn_116_157DC(void* object, short deleting) {
    if (object != 0) {
        short minus_one = -1;
        fn_116_20D8((char*)object + 0x14b0, minus_one);
        fn_116_229C((char*)object + 0x138c, minus_one);
        fn_116_158B4((char*)object + 0x1260, minus_one);
        fn_116_15940((char*)object + 0x1134, minus_one);
        fn_116_159CC((char*)object + 0x1008, minus_one);
        fn_116_15A58((char*)object + 0xedc, minus_one);
        fn_116_15AE4((char*)object + 0xdb0, minus_one);
        fn_116_15B70((char*)object + 0xc84, minus_one);
        fn_116_15BFC((char*)object + 0xb58, minus_one);
        fn_116_15C88((char*)object + 0xa2c, minus_one);
        fn_116_15D14(object, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}