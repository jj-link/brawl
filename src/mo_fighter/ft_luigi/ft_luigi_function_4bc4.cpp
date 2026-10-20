#pragma force_active on
extern "C" {
void* fn_27_D2904(void* member, short deleteFlag);
void* fn_99_4C3C(void* object, short deleteFlag);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_99_4BC4(void* object, short deleting) {
    if (object) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object) {
            fn_99_4C3C(object, 0);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
