#pragma force_active on
extern "C" void* fn_99_3C6C(void*, short);

extern "C" void* fn_99_4F64(void* object, short deleting) {
    if (object) {
        fn_99_3C6C(static_cast<unsigned char*>(object) + 0x88, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
