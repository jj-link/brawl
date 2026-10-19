#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_58CC(void*, short);
extern "C" void* fn_95_5CA8(void*, short);

extern "C" void* fn_95_585C(void* object, short deleting) {
    if (object != 0) {
        fn_95_58CC(static_cast<unsigned char*>(object) + 0x3FC8, -1);
        fn_95_5CA8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
