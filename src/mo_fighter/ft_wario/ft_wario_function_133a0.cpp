#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void fn_110_13340(void* object, short deleting);
extern "C" void* fn_110_13270(void* object, short deleting);

extern "C" void* fn_110_133A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_13340(storage + 0x64, -1);
        if (object != 0) {
            fn_110_13270(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
