#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_A694(void*, short);
extern "C" void* fn_109_A574(void*, short);

extern "C" void* fn_109_A6F4(void* object, short deleting) {
    if (object != 0) {
        fn_109_A694(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_109_A574(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
