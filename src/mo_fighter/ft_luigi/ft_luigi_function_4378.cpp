#pragma force_active on
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_99_3D08(void*, short);

extern "C" void* fn_99_4378(void* object, short deleting) {
    if (object) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_99_3D08(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
