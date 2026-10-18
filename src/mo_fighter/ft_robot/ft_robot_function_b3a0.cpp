#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_9940(void*, short);

extern "C" void* fn_120_B3A0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_120_9940(object, 0);
        }

        if (deleting > 0) {
            operator delete(object);
        }
    }

    return object;
}
