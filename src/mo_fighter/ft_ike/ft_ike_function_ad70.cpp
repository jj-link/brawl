#pragma force_active on
void operator delete(void*);

extern "C" void* fn_119_AD10(void*, short);

extern "C" void* fn_119_AD70(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_119_AD10(static_cast<unsigned char*>(object) + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
