#pragma force_active on
extern "C" {
void* fn_91_4668(void*, short);

void* fn_91_46A8(void* object, short deleting) {
    if (object != 0) {
        fn_91_4668(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
