#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_1A03C(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_117_1A0AC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_1A03C(static_cast<unsigned char*>(object) + 0xCC, memberDeleting);
        short baseDeleting = 0;
        fn_27_1D81C8(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
