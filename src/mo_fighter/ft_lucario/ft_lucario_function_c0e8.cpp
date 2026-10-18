#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_C088(void*, short);

extern "C" void* fn_118_C0E8(void* object, short deleting) {
    if (object != 0) {
        fn_118_C088(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
