#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_117_52E4(void* object, short deleting);

extern "C" void* fn_117_5274(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, memberDeleting);
        short baseDeleting = 0;
        fn_117_52E4(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
