#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_2394(void*, short);
extern "C" void* fn_117_21F0(void*, short);

extern "C" void* fn_117_2328(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_2394(storage + 0x50, -1);
        fn_117_21F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
