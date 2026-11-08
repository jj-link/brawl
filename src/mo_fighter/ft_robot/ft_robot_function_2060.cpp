#pragma force_active on
extern "C" {
void* fn_120_2138(void*, short);
void* fn_120_22FC(void*, short);
void* fn_120_23C4(void*, short);
void* fn_120_2450(void*, short);
void* fn_120_24DC(void*, short);
void* fn_120_2568(void*, short);
void* fn_120_25F4(void*, short);
void* fn_120_2680(void*, short);
void* fn_120_270C(void*, short);
void* fn_120_2798(void*, short);
void* fn_120_2824(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_2060(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_120_2138(storage + 0x14a8, destroy);
        fn_120_22FC(storage + 0x1384, destroy);
        fn_120_23C4(storage + 0x1258, destroy);
        fn_120_2450(storage + 0x112c, destroy);
        fn_120_24DC(storage + 0x1000, destroy);
        fn_120_2568(storage + 0xed4, destroy);
        fn_120_25F4(storage + 0xda8, destroy);
        fn_120_2680(storage + 0xc7c, destroy);
        fn_120_270C(storage + 0xb50, destroy);
        fn_120_2798(storage + 0xa24, destroy);
        fn_120_2824(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
