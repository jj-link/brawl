#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_17508(void*, short);

extern "C" void* fn_121_174A8(void* object, short deleting) {
    if (object != 0) {
        fn_121_17508(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
