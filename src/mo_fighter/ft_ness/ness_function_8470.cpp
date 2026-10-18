#pragma force_active on
void operator delete(void*);

extern "C" void* fn_101_8470(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
