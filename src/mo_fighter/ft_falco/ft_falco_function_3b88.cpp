#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_3C2C(void*, short);
extern "C" void* fn_108_3CB0(void*, short);
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void* fn_108_3D10(void*, short);
extern "C" void* fn_108_3E38(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_108_3B88(void* object, short deleting) {
    if (object != 0) {
        fn_108_3C2C(static_cast<unsigned char*>(object) + 0x110, -1);
        fn_108_3CB0(static_cast<unsigned char*>(object) + 0xFC, -1);
        if (static_cast<unsigned char*>(object) + 0xEC != 0) {
            fn_27_1A2D10(static_cast<unsigned char*>(object) + 0xEC, -1);
        }
        fn_108_3D10(static_cast<unsigned char*>(object) + 0x48, -1);
        fn_108_3E38(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
