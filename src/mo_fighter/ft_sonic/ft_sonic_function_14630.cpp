#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_146A0(void*, short);
extern "C" void* fn_123_1496C(void*, short);

extern "C" void* fn_123_14630(void* object, short deleting) {
    if (object != 0) {
        fn_123_146A0(static_cast<unsigned char*>(object) + 0x252C, -1);
        fn_123_1496C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
