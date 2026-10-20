#pragma force_active on
extern "C" void* fn_99_A450(void* object, short deleting);
extern "C" void* fn_99_A31C(void* object, short deleting);

extern "C" void* fn_99_A4B0(void* object, short deleting) {
    if (object) {
        fn_99_A450(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object) fn_99_A31C(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
