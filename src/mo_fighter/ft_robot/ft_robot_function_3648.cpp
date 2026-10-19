#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_36B8(void*, short);
extern "C" void* fn_120_3778(void*, short);

extern "C" void* fn_120_3648(void* object, short deleting) {
    if (object != 0) {
        fn_120_36B8(static_cast<unsigned char*>(object) + 0x221C, -1);
        fn_120_3778(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
