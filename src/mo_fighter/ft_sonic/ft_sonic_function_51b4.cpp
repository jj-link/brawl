#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_A8C0(void*, short);
extern "C" void* fn_123_4E64(void*, short);
extern "C" void* fn_123_4ED4(void*, short);

extern "C" void* fn_123_51B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_A8C0(storage + 0xE0, -1);
        fn_123_4E64(storage + 0x30, -1);
        fn_123_4ED4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
