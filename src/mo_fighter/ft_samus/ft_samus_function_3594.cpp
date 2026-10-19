#pragma force_active on
extern "C" {
void fn_94_3610(void* object, short deleting);
void fn_94_37A8(void* object, short deleting);
void __dl__FPv(void* object);

void* fn_94_3594(void* object, short deleting) {
    if (object != 0) {
        fn_94_3610(static_cast<char*>(object) + 0x12604, -1);
        if (object != 0) {
            fn_94_37A8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
