#pragma force_active on
extern "C" {
void* fn_27_5B39C(void*, short);

void* fn_91_3D28(void* object, short deleting) {
    if (object != 0) {
        fn_27_5B39C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
