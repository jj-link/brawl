#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_117_13ED4(void*, short);
extern "C" void* fn_117_13E94(void*, short);

extern "C" void* fn_117_13F30(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x20, memberDeleting);
        fn_117_13ED4(static_cast<unsigned char*>(object) + 0x10, memberDeleting);
        if (object != 0) {
            fn_117_13E94(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
