#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_1C9A0(void* object, short deleting);
extern "C" void* fn_113_1C8C8(void* object, short deleting);

extern "C" void* fn_113_1CA00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_1C9A0(storage + 0x10C, -1);
        if (object != 0) {
            fn_113_1C8C8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
