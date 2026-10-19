#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_102_3B28(void* p, short n);

extern "C" void* fn_102_43D4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_102_3B28(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
