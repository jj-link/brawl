#pragma force_active on
extern "C" void* fn_99_3EEC(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}
