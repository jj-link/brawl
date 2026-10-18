#pragma force_active on
void operator delete(void*);
extern "C" void fn_101_F904(void*, short);

extern "C" void* fn_101_F964(void* object, short deleting) {
    if (object != 0) {
        fn_101_F904(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
