#pragma force_active on
extern "C" void* fn_99_5D54(void* object, short deleting);

extern "C" void* fn_99_5CF8(void* object, short deleting) {
    if (object) {
        fn_99_5D54(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
