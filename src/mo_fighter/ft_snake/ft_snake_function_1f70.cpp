#pragma force_active on
extern "C" {
void* fn_122_1FF4(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_122_28AC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_122_1F70(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_122_1FF4(static_cast<char*>(object) + 0x2B264, destroy);
        fn_27_C74E8(static_cast<char*>(object) + 0x2B254, destroy);
        fn_122_28AC(object, short(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
