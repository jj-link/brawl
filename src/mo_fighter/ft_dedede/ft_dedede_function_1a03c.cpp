#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_19FAC(void*, short);
extern "C" void* fn_117_19C20(void*, short);

extern "C" void* fn_117_1A03C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_19FAC(static_cast<unsigned char*>(object) + 0x16C4, memberDeleting);
        short baseDeleting = 0;
        fn_117_19C20(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
