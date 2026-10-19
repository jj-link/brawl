#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_335C(void*, short);
extern "C" void* fn_117_43A8(void*, short);

extern "C" void* fn_117_32EC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_335C(static_cast<unsigned char*>(object) + 0x8, memberDeleting);
        short baseDeleting = 0;
        fn_117_43A8(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
