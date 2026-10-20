#pragma force_active on
extern "C" void* fn_114_D288(void* object, short deleting);
extern "C" void* fn_114_6D9C(void* object, short deleting);
extern "C" void* fn_114_6E0C(void* object, short flag);

extern "C" void* fn_114_6D24(void* object, short flag) {
    if (object != 0) {
        fn_114_D288((char*)object + 0xE0, (short)-1);
        fn_114_6D9C((char*)object + 0x30, (short)-1);
        fn_114_6E0C(object, (short)-1);
        if (flag > 0) {
            delete object;
        }
    }
    return object;
}
