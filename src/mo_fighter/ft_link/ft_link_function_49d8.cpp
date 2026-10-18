#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);

extern "C" void* fn_93_49D8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A15B8(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
