#pragma force_active on
extern "C" void* fn_98_394C(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_98_BF14(void* object, int deleting) {
    if (object) {
        if (object) fn_98_394C(object, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
