#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_116_20D8(void*, short);
void* fn_116_229C(void*, short);
void* fn_116_2364(void*, short);
void* fn_116_23F0(void*, short);
void* fn_116_247C(void*, short);
void* fn_116_2508(void*, short);
void* fn_116_2594(void*, short);
void* fn_116_2620(void*, short);
void* fn_116_26AC(void*, short);
void* fn_116_2738(void*, short);
void* fn_116_27C4(void*, short);
}
extern "C" void* fn_116_2000(void* object, short deleting) {
    if (object != 0) {
        short minus_one = -1;
        fn_116_20D8((char*)object + 0x1480, minus_one);
        fn_116_229C((char*)object + 0x135c, minus_one);
        fn_116_2364((char*)object + 0x1230, minus_one);
        fn_116_23F0((char*)object + 0x1104, minus_one);
        fn_116_247C((char*)object + 0xfd8, minus_one);
        fn_116_2508((char*)object + 0xeac, minus_one);
        fn_116_2594((char*)object + 0xd80, minus_one);
        fn_116_2620((char*)object + 0xc54, minus_one);
        fn_116_26AC((char*)object + 0xb28, minus_one);
        fn_116_2738((char*)object + 0x9fc, minus_one);
        fn_116_27C4(object, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}