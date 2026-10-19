#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_17DD0(void*, short);
extern "C" void* fn_120_17A38(void*, short);

extern "C" void* fn_120_17E60(void* object, short deleting) {
    if (object != 0) {
        fn_120_17DD0(static_cast<unsigned char*>(object) + 0x1B10, -1);
        fn_120_17A38(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
