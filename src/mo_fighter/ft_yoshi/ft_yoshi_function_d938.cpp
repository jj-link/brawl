#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_D8D8(void* object, short deleting);
extern "C" void fn_95_D7A4(void* object, short deleting);

extern "C" void* fn_95_D938(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_D8D8(storage + 0x134, -1);
        if (object != 0) {
            fn_95_D7A4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
