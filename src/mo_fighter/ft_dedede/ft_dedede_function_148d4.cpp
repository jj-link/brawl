#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_63EBC(void*, short);

extern "C" void* fn_117_148D4(void* object, short deleting) {
    if (object != 0) {
        fn_27_63EBC(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
