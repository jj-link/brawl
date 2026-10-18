#pragma force_active on
extern "C" {
void* fn_91_2C5C(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
}
