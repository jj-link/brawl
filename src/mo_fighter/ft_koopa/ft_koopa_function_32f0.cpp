#pragma force_active on
void operator delete(void*);

extern "C" void fn_102_3350(void*, short);

extern "C" void* fn_102_32F0(void* object, short deleting) {
    if (object != 0) {
        fn_102_3350(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
