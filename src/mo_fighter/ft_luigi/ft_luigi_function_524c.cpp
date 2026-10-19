#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_199E3C(void*, short);

extern "C" void* fn_99_524C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_6A3D8(storage + 0x144, destroyMember);
        fn_27_199E3C(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
