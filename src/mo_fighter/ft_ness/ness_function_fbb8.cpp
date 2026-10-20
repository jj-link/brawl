#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_FB58(void*, short);
void* fn_101_FA24(void*, short);
}

extern "C" void* fn_101_FBB8(void* object, short deleting) {
    if (object != 0) {
        fn_101_FB58(static_cast<unsigned char*>(object) + 0x1C8, static_cast<short>(-1));
        if (object != 0) {
            fn_101_FA24(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
