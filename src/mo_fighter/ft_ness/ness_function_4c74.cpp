#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_101_4CF0(void*, short);
void fn_101_528C(void*, short);
}

extern "C" void* fn_101_4C74(void* object, short deleting) {
    if (object != 0) {
        fn_101_4CF0(static_cast<unsigned char*>(object) + 0x3C0C4, static_cast<short>(-1));
        if (object != 0) {
            fn_101_528C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
