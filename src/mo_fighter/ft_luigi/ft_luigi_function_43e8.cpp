#pragma force_active on
extern "C" void* fn_99_1E9C(void*, short);
extern "C" void* fn_99_3D48(void*, short);

extern "C" void* fn_99_43E8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = 0;
        fn_99_1E9C(storage + 0x20, destroyMember);
        fn_99_3D48(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
