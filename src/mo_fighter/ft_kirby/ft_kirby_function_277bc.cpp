#pragma force_active on
void operator delete(void*);

extern "C" void* fn_96_84BC(void*, short);

extern "C" void* fn_96_277BC(void* object, short deleting) {
    if (object != 0) {
        fn_96_84BC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
