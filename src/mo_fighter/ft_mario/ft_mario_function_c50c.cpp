#pragma force_active on
extern "C" {
void* fn_91_C374(void*, short);

void* fn_91_C50C(void* object, short deleting) {
    if (object != 0) {
        fn_91_C374(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
