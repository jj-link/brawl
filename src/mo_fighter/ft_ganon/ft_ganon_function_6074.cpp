#pragma force_active on
extern "C" void* fn_109_41F0(void*, short);

extern "C" void* fn_109_6074(void* obj, short baseDeleting) {
    if (obj != 0) {
        fn_109_41F0(obj, 0);
        if (baseDeleting > 0) {
            operator delete(obj);
        }
    }
    return obj;
}
