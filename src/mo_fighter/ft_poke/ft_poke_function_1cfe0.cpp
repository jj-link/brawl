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
void* fn_116_1D0B8(void*, short);
}
extern "C" void* fn_116_1CFE0(void* object, short deleting) {
    if (object != 0) {
        short minus_one = -1;
        fn_116_20D8((char*)object + 0x1490, minus_one);
        fn_116_229C((char*)object + 0x136c, minus_one);
        fn_116_2364((char*)object + 0x1240, minus_one);
        fn_116_23F0((char*)object + 0x1114, minus_one);
        fn_116_247C((char*)object + 0xfe8, minus_one);
        fn_116_2508((char*)object + 0xebc, minus_one);
        fn_116_2594((char*)object + 0xd90, minus_one);
        fn_116_2620((char*)object + 0xc64, minus_one);
        fn_116_26AC((char*)object + 0xb38, minus_one);
        fn_116_2738((char*)object + 0xa0c, minus_one);
        fn_116_1D0B8(object, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}