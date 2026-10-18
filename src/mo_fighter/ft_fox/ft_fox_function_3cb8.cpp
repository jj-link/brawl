#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_3D5C(void*, short);
extern "C" void* fn_97_3DE0(void*, short);
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void* fn_97_3E40(void*, short);
extern "C" void* fn_97_3F68(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_97_3CB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_3D5C(storage + 0x110, -1);
        fn_97_3DE0(storage + 0xFC, -1);
        if (storage + 0xEC != 0) {
            fn_27_1A2D10(storage + 0xEC, -1);
        }
        fn_97_3E40(storage + 0x48, -1);
        fn_97_3F68(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
