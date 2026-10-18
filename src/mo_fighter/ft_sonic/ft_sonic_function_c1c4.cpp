#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_C164(void*, short);

extern "C" void* fn_123_C1C4(void* object, short deleting) {
    if (object != 0) {
        fn_123_C164(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
