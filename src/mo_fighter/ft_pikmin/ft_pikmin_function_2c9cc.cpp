#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_2A10(void*, short);

extern "C" void* fn_113_2C9CC(void* object, short deleting) {
    if (object != 0) {
        fn_113_2A10(static_cast<unsigned char*>(object) + 0x58, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
