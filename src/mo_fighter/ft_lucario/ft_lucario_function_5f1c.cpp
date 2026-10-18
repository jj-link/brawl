#pragma force_active on
void operator delete(void*);

extern "C" void* fn_118_5F1C(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
