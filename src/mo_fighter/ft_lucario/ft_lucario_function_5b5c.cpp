#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_3B70(void*, short);

extern "C" void* fn_118_5B5C(void* object, short deleting) {
    if (object != 0) {
        fn_118_3B70(static_cast<unsigned char*>(object) + 0x88, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
