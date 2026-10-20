#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_F9C4(void*, short);
void* fn_101_F88C(void*, short);
}

extern "C" void* fn_101_FA24(void* object, short deleting) {
    if (object != 0) {
        fn_101_F9C4(static_cast<unsigned char*>(object) + 0x17C, static_cast<short>(-1));
        if (object != 0) {
            fn_101_F88C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
