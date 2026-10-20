#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_123_5744(void*, short);

extern "C" void* fn_123_56CC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x2fc, -1);
        if (object != 0) {
            fn_123_5744(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
