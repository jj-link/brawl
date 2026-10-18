#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_7040(void*, short);
}

extern "C" void* fn_101_6FE0(void* object, short deleting) {
    if (object != 0) {
        fn_101_7040(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
