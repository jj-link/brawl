#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_9684(void*, short);
extern "C" void fn_96_6780(void*, short);

extern "C" void* fn_96_96E0(void* object, short deleting) {
    if (object != 0) {
        fn_96_9684(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_96_6780(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
