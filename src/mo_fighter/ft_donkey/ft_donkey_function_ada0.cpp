#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_AD40(void*, short);

extern "C" void* fn_92_ADA0(void* object, short deleting) {
    if (object != 0) {
        fn_92_AD40(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
