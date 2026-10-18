#pragma force_active on
void operator delete(void*);

extern "C" void* fn_117_13E94(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
