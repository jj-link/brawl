#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_32D4(void*, short);
extern "C" void* fn_123_5094(void*, short);

extern "C" void* fn_123_3264(void* object, short deleting) {
    if (object != 0) {
        fn_123_32D4(static_cast<unsigned char*>(object) + 8, -1);
        fn_123_5094(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
