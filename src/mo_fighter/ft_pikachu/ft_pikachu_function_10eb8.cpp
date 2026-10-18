#pragma force_active on
extern "C" void* fn_98_10EB8(void* object, int deleting) {
    if (object && static_cast<short>(deleting) > 0) operator delete(object);
    return object;
}
