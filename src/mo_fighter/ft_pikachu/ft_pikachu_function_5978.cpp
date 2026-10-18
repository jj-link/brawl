#pragma force_active on
extern "C" void* fn_98_59D8(void*, short);

extern "C" void* fn_98_5978(void* object, int deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_98_59D8(object, static_cast<short>(0));
        }

        if (static_cast<short>(deleting) > 0) {
            operator delete(object);
        }
    }

    return object;
}
