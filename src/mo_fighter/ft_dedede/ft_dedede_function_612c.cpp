#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_19C818(void*, short);

extern "C" void* fn_117_612C(void* object, short deleting) {
    if (object != 0) {
        fn_27_19C818(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
