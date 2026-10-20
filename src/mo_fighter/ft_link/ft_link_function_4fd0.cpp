#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_93_4F58(void*, short);

extern "C" void* fn_93_4FD0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x2fc, -1);
        if (object != 0) {
            fn_93_4F58(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
