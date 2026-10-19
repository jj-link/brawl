#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_689B0(void*, short);
extern "C" void fn_27_1985B4(void*, short);

extern "C" void* fn_101_84B0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_689B0(static_cast<unsigned char*>(object) + 0x7C, memberDeleting);

        if (object != 0) {
            fn_27_1985B4(object, memberDeleting);
        }

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
