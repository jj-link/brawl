#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_6314(void*, short);

extern "C" void* fn_117_62B8(void* object, short deleting) {
    if (object != 0) {
        fn_117_6314(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
