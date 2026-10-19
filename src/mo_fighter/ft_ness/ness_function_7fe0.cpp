#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_101_8050(void*, short);
}

extern "C" void* fn_101_7FE0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, static_cast<short>(-1));
        fn_101_8050(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
