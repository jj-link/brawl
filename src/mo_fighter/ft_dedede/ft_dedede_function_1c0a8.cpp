#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_14D34(void*, short);
extern "C" void* fn_117_1BF1C(void*, short);

extern "C" void* fn_117_1C0A8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_14D34(static_cast<unsigned char*>(object) + 0x18BC, memberDeleting);
        short baseDeleting = 0;
        fn_117_1BF1C(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
