#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_1F0B8(void*, short);
extern "C" void* fn_117_1ECCC(void*, short);

extern "C" void* fn_117_1F148(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_1F0B8(static_cast<unsigned char*>(object) + 0x1FC4, memberDeleting);
        short baseDeleting = 0;
        fn_117_1ECCC(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
