#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_3E14(void*, short);

extern "C" void* fn_101_1C160(void* object, short deleting) {
    if (object != 0) {
        fn_101_3E14(static_cast<unsigned char*>(object) + 0x1C,
                     static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
