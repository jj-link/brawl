#pragma force_active on
extern "C" {
void* fn_91_6124(void*, short);

void* fn_91_C838(void* object, short deleting) {
    if (object != 0) {
        fn_91_6124(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
