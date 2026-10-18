#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_1E13C(void*, short);

extern "C" void* fn_96_1E01C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_96_1E13C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
