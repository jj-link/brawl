#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_125_4E6C(void*, short);
extern "C" void* fn_125_1FC8(void*, short);
extern "C" void* fn_125_4EAC(void*, short);

extern "C" void* fn_125_4DD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_125_4E6C(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_125_1FC8(storage + 0x20, 0);
            fn_125_4EAC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
