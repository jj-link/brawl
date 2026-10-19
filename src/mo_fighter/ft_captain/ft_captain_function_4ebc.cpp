#pragma force_active on

extern "C" void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_100_3BE0(void*, short);

extern "C" void* fn_100_4EBC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A20EC(storage + 0x10, -1);
        fn_100_3BE0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
