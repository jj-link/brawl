#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_B8A4(void* object, short deleting);
extern "C" void* fn_123_B784(void* object, short deleting);

extern "C" void* fn_123_B904(void* object, short deleting) {
    if (object != 0) {
        fn_123_B8A4(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_123_B784(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
