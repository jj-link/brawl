#pragma force_active on
extern "C" {
void fn_27_7700(void*, short);

void* fn_91_19B8(void* object, short deleting) {
    if (object != 0) {
        fn_27_7700(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
