#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_B6F0(void* object, short deleting);
extern "C" void fn_110_B5BC(void* object, short deleting);

extern "C" void* fn_110_B750(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_B6F0(storage + 0x204, -1);
        if (object != 0) {
            fn_110_B5BC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
