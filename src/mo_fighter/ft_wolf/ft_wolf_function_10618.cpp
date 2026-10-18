#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_3720(void*, short);

extern "C" void* fn_125_10618(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_125_3720(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
