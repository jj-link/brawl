#pragma force_active on
extern "C" void* fn_95_349C(void* object, short deleting);

extern "C" void* fn_95_3440(void* obj, short deleting) {
    if (obj != 0) {
        fn_95_349C(obj, 0);
        if (deleting > 0) {
            operator delete(obj);
        }
    }
    return obj;
}
