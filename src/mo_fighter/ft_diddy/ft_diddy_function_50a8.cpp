#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_115_5120(void* object, short flag);

extern "C" void* fn_115_50A8(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_115_5120(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
