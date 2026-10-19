#pragma force_active on
extern "C" {
void* fn_27_ACC5C(void*, short);

void* fn_91_8494(void* object, short deleting) {
    if (object != 0) {
        fn_27_ACC5C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
