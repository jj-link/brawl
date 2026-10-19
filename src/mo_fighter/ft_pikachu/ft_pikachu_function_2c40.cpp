#pragma force_active on
extern "C" void* fn_27_C21DC(void*, short);

extern "C" void* fn_98_2C40(void* object, int deleting) {
    if (object) {
        fn_27_C21DC(object, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
