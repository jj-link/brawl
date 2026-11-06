#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_107_2208(void*, short);
void* fn_107_23CC(void*, short);
void* fn_107_2494(void*, short);
void* fn_107_2520(void*, short);
void* fn_107_25AC(void*, short);
void* fn_107_2638(void*, short);
void* fn_107_26C4(void*, short);
void* fn_107_2750(void*, short);
void* fn_107_27DC(void*, short);
void* fn_107_2868(void*, short);
void* fn_107_28F4(void*, short);
}
extern "C" void* fn_107_2130(void* object, short deleting) {
    if (object) {
        char* p = (char*)object;
        fn_107_2208(p + 0x1580, -1);
        fn_107_23CC(p + 0x145C, -1);
        fn_107_2494(p + 0x1330, -1);
        fn_107_2520(p + 0x1204, -1);
        fn_107_25AC(p + 0x10D8, -1);
        fn_107_2638(p + 0xFAC, -1);
        fn_107_26C4(p + 0xE80, -1);
        fn_107_2750(p + 0xD54, -1);
        fn_107_27DC(p + 0xC28, -1);
        fn_107_2868(p + 0xAFC, -1);
        fn_107_28F4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}