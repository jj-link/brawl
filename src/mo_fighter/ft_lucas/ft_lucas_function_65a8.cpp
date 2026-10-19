#pragma force_active on
extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void fn_114_6614(void* object, short deleting);

extern "C" void* fn_114_65A8(char* object, short deleting) {
    if (object != 0) {
        fn_114_5D0C(object + 0x3838, -1);
        fn_114_6614(object + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
