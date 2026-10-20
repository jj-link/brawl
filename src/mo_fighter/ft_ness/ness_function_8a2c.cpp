#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_101_8AA4(void*, short);
extern "C" void* fn_101_8B04(void*, short);

extern "C" void* fn_101_8A2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x30, -1);
        fn_101_8AA4(storage + 0x18, -1);
        fn_101_8B04(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
