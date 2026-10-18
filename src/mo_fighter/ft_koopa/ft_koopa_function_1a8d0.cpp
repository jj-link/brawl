#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_3BC8(void* object, short deleting);
extern "C" void* fn_102_3C4C(void* object, short deleting);
extern "C" void* fn_102_1A96C(void* object, short deleting);
extern "C" void* fn_102_1A9C8(void* object, short deleting);
extern "C" void* fn_102_1AAFC(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_102_1A8D0(void* object, short deleting) {
    if (object != 0) {
        fn_102_3BC8((char*)object + 0x110, -1);
        fn_102_3C4C((char*)object + 0xfc, -1);
        fn_102_1A96C((char*)object + 0xec, -1);
        fn_102_1A9C8((char*)object + 0x48, -1);
        fn_102_1AAFC((char*)object + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
