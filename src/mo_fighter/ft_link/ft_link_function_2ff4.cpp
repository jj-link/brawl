#pragma force_active on
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_93_2F88(void*, short);
void* fn_27_21038(void*, short);
void* fn_93_2F2C(void*, short);
void* fn_93_2ED0(void*, short);
void* fn_93_2C0C(void*, short);
void* fn_93_2E74(void*, short);
void* fn_93_2DFC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_93_2FF4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_13C90(storage + 0x224, destroy);
        fn_93_2F88(storage + 0x1e8, destroy);
        fn_27_21038(storage + 0x1d8, destroy);
        fn_93_2F2C(storage + 0x1b8, destroy);
        fn_93_2ED0(storage + 0x198, destroy);
        fn_93_2C0C(storage + 0x160, destroy);
        fn_93_2E74(storage + 0xc4, destroy);
        fn_93_2DFC(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
