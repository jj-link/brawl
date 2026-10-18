#pragma force_active on
extern "C" void* fn_113_E4A4(void*, short);
void operator delete(void*);

extern "C" void* fn_113_E504(void* object, short deleting) {
    if (object != 0) {
        fn_113_E4A4(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
