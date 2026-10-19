#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_25740(void*, short);
extern "C" void* fn_27_CC0F0(void*, short);

extern "C" void* fn_123_44C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_25740(storage + 0x50, -1);
        fn_27_CC0F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
