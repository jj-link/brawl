#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_572C(void*, short);
void* fn_101_18430(void*, short);
}

extern "C" void* fn_101_183BC(void* object, short deleting) {
    if (object != 0) {
        fn_101_572C(static_cast<unsigned char*>(object) + 0xD6D8, static_cast<short>(-1));
        fn_101_18430(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
