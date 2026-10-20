#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_B248(void* object, short deleting);
extern "C" void fn_92_B110(void* object, short deleting);

extern "C" void* fn_92_B2A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_B248(storage + 0xEC, -1);
        if (object != 0) {
            fn_92_B110(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
