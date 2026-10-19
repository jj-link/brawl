#pragma force_active on
extern "C" void* fn_107_39E0(void*, short);

extern "C" void* fn_107_3984(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_107_39E0(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
