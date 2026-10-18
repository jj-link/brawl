#pragma force_active on
void operator delete(void*);

extern "C" void* fn_123_B9D4(void*, short);

extern "C" void* fn_123_BA34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* subobject = static_cast<unsigned char*>(object) + 8;
        short memberDeleting = -1;
        fn_123_B9D4(subobject, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
