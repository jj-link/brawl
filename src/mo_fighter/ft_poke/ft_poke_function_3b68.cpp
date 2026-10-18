#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A220C(void*, short);
extern "C" void* fn_116_3C04(void*, short);
extern "C" void* fn_116_1F20(void*, short);
extern "C" void* fn_116_3C44(void*, short);

extern "C" void* fn_116_3B68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A220C(storage + 0x40, -1);
            fn_116_3C04(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_116_1F20(storage + 0x20, 0);
            fn_116_3C44(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
