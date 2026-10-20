#pragma force_active on
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void* fn_99_4A5C(void*, short);

extern "C" void* fn_99_49E4(void* object, short deleting) {
    if (object) {
        fn_27_1A1FE4(static_cast<unsigned char*>(object) + 0x244, -1);
        if (object) {
            fn_99_4A5C(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
