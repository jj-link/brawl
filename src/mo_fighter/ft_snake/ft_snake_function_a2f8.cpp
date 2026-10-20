#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_122_A370(void* object, short deleting);
extern "C" void* fn_122_A3D0(void* object, short deleting);

extern "C" void* fn_122_A2F8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x30, memberDeleting);
        fn_122_A370(static_cast<unsigned char*>(object) + 0x18, memberDeleting);
        fn_122_A3D0(static_cast<unsigned char*>(object) + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
