#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_6A3D8(void*, short);
void* fn_27_199E3C(void*, short);
}

extern "C" void* fn_98_658C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_6A3D8(static_cast<char*>(object) + 0x144, memberDeleting);
        fn_27_199E3C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
