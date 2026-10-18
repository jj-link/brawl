#pragma force_active on
void operator delete(void*);

extern "C" void* fn_113_EC94(void*, short);

extern "C" void* fn_113_1C808(void* object, short deleting) {
    if (object != 0) {
        fn_113_EC94(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
