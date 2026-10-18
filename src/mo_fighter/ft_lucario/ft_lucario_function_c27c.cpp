#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_C21C(void*, short);

extern "C" void* fn_118_C27C(void* object, short deleting) {
    if (object != 0) {
        fn_118_C21C(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
