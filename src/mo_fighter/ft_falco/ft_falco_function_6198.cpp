#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_108_4E14(void*, short);

extern "C" void* fn_108_6198(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_108_4E14(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
