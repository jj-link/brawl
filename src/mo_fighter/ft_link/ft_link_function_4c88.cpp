#pragma force_active on
extern "C" void fn_27_1A15B8(void*, short);
extern "C" void fn_93_4C10(void*, short);
void operator delete(void*);

extern "C" void* fn_93_4C88(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x138, -1);
        if (object != 0) {
            fn_93_4C10(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
