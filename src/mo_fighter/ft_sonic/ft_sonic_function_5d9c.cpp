#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_5E08(void*, short);
extern "C" void* fn_123_4068(void*, short);

extern "C" void* fn_123_5D9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_5E08(storage + 0x24, -1);
        fn_123_4068(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
