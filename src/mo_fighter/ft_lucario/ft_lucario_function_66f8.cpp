#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_19C818(void*, short);

extern "C" void* fn_118_66F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_19C818(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
