#pragma force_active on
extern "C" {
void* fn_91_1B20(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
}
