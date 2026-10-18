#pragma force_active on
extern "C" void* fn_117_32EC(void*, short);
void operator delete(void*);

extern "C" void* fn_117_3290(void* object, short deleting) {
    if (object != 0) {
        fn_117_32EC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
