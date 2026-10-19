#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_17580(void*, short);
extern "C" void* fn_123_17460(void*, short);

extern "C" void* fn_123_175E0(void* object, short deleting) {
    if (object != 0) {
        fn_123_17580(static_cast<unsigned char*>(object) + 0x44, -1);
        fn_123_17460(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
