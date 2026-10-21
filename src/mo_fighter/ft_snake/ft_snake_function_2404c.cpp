#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_39B4(void*, short);
extern "C" void* fn_122_62F4(void*, short);
extern "C" void* fn_122_6380(void*, short);
extern "C" void* fn_122_640C(void*, short);
extern "C" void* fn_122_56C8(void*, short);

extern "C" void* fn_122_2404C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_39B4(storage + 0x4B0, -1);
        fn_122_62F4(storage + 0x384, -1);
        fn_122_6380(storage + 0x258, -1);
        fn_122_640C(storage + 0x12C, -1);
        fn_122_56C8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
