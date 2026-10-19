#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_33C0(void*, short);
extern "C" void fn_102_4098(void*, short);

extern "C" void* fn_102_402C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_33C0(storage + 0x7E28, -1);
        fn_102_4098(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
