#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void fn_107_6FC4(void* object, short flag);
void __dl__FPv(void* obj);
}

extern "C" void* fn_107_6F4C(void* object, short flag) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2d0, -1);
        void* base = object;
        if (base != 0) {
            short baseDeleteFlag = 0;
            fn_107_6FC4(base, baseDeleteFlag);
        }
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
