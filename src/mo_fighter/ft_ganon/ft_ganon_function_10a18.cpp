#pragma force_active on
void operator delete(void*);

extern "C" void* fn_109_10A74(void* object, short deleting);

extern "C" void* fn_109_10A18(void* object, short deleting) {
    if (object != 0) {
        fn_109_10A74(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
