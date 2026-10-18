#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_112_4808(void*, short);
extern "C" void* fn_112_1FA8(void*, short);
extern "C" void* fn_112_4848(void*, short);

extern "C" void* fn_112_476C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_112_4808(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_112_1FA8(storage + 0x20, 0);
            fn_112_4848(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
