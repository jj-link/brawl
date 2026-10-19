#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);

// Destroy the embedded member, then the base; free storage when requested.
extern "C" void* fn_117_5ACC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_4B53C(storage + 0x17C, memberDeleting);
        fn_27_19C45C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
