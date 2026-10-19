#pragma force_active on
extern "C" void* fn_120_12A80(void* object, short deleting);

extern "C" void* fn_120_12AE0(void* obj, short flag) {
    if (obj != 0) {
        fn_120_12A80(obj, 0);
        if (flag > 0) {
            operator delete(obj);
        }
    }
    return obj;
}
