#pragma force_active on
void operator delete(void*);

extern "C" void* fn_118_10178(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
