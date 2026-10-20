#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_116_3E10(void* ptr, short flag);
extern "C" void* fn_116_3E50(void* object, short deleting);

extern "C" void* fn_116_3D88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_116_3E10(storage + 0x24, 0);
        }
        fn_116_3E50(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
