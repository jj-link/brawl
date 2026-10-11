extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_CBB00(void*, short);

extern "C" void* fn_99_FA50(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_6A3D8(storage + 0x110, destroyMember);
        fn_27_CBB00(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
