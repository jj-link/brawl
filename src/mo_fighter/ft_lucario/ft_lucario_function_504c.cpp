#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_3D48(void*, short);
extern "C" void* fn_118_3DCC(void*, short);
extern "C" void* fn_118_50E8(void*, short);
extern "C" void* fn_118_5144(void*, short);
extern "C" void* fn_118_5B5C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_118_504C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3D48(storage + 0xDE4, -1);
        fn_118_3DCC(storage + 0xDD0, -1);
        fn_118_50E8(storage + 0x930, -1);
        fn_118_5144(storage + 0xBC, -1);
        fn_118_5B5C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
