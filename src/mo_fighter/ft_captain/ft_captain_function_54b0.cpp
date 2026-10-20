#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void* fn_100_5528(void* object, short flag);
void __dl__FPv(void* obj);
}

extern "C" void* fn_100_54B0(void* object, short flag) {
    if (object != 0) {
        short memberDeleteFlag = -1;
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2d0, memberDeleteFlag);
        void* base = object;
        if (base != 0) {
            short baseDeleteFlag = 0;
            fn_100_5528(base, baseDeleteFlag);
        }
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
