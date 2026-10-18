#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_1E07C(void*, short);

extern "C" void* fn_96_1DDB0(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_96_1E07C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
