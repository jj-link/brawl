#pragma force_active on
extern "C" void* fn_123_17120(void* object, short deleting);
extern "C" void* fn_123_4E64(void* object, short deleting);
extern "C" void* fn_123_4ED4(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_123_14C10(void* object, short deleting) {
    if (object != 0) {
        fn_123_17120(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_123_4E64(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_123_4ED4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
