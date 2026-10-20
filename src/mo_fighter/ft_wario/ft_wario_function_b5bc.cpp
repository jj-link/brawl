#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_B55C(void* object, short deleting);
extern "C" void* fn_110_B428(void* object, short deleting);

extern "C" void* fn_110_B5BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_B55C(storage + 0x1C8, -1);
        if (object != 0) {
            fn_110_B428(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
