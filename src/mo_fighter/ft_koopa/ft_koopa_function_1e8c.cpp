#pragma force_active on
extern "C" void* fn_27_7700(void*, short);

extern "C" void* fn_102_1E8C(void* object, short deleting) {
    if (object != 0) {
        fn_27_7700(object, static_cast<short>(0));
        if (deleting > 0) {
            delete object;
        }
    }
    return object;
}

