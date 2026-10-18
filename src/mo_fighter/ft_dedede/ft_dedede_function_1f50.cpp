#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_7700(void*, short);

extern "C" void* fn_117_1F50(void* object, short deleting) {
    if (object != 0) {
        fn_27_7700(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
