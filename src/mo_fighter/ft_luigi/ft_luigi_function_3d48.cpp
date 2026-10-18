#pragma force_active on
extern "C" void* fn_99_1E40(void*, short);

extern "C" void* fn_99_3D48(void* object, short deleting) {
    if (object) {
        fn_99_1E40(static_cast<unsigned char*>(object) + 0x8, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
