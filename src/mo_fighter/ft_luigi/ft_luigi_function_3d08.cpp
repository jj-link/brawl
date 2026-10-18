#pragma force_active on
extern "C" void* fn_99_3D08(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
