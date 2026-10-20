#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_B3C8(void* object, short deleting);
extern "C" void* fn_110_B290(void* object, short deleting);

extern "C" void* fn_110_B428(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_B3C8(storage + 0x17c, -1);
        if (object != 0) {
            fn_110_B290(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
