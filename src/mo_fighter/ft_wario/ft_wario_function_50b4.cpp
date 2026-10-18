#pragma force_active on
void operator delete(void*);

extern "C" void* fn_110_3D08(void*, short);

extern "C" void* fn_110_50B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_3D08(members + 0x1C0, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
