#pragma force_active on
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_99_18A4(void*, short);

extern "C" void* fn_99_85F0(void* object, short deleting) {
    if (object) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0xE1F4, -1);
        fn_99_18A4(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
