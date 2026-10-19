#pragma force_active on
extern "C" void* fn_118_B7E0(void*, short);
extern "C" void* fn_118_B900(void*, short);

void operator delete(void*);

extern "C" void* fn_118_B960(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_B900(storage + 0x60, -1);
        fn_118_B7E0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
