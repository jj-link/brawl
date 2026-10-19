#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_230EC(void*, short);
void* fn_101_23320(void*, short);
}

extern "C" void* fn_101_2307C(void* object, short deleting) {
    if (object != 0) {
        fn_101_230EC(static_cast<unsigned char*>(object) + 0x1A70, static_cast<short>(-1));
        fn_101_23320(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
