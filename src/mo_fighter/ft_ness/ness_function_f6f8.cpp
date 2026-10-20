#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_F698(void*, short);
void* fn_101_F560(void*, short);
}

extern "C" void* fn_101_F6F8(void* object, short deleting) {
    if (object != 0) {
        fn_101_F698(static_cast<unsigned char*>(object) + 0xEC, static_cast<short>(-1));
        if (object != 0) {
            fn_101_F560(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
