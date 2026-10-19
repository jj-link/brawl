#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_5C28(void*, short);
extern "C" void* fn_118_407C(void*, short);

extern "C" void* fn_118_5BBC(void* object, short deleting) {
    if (object != 0) {
        fn_118_5C28(static_cast<unsigned char*>(object) + 0x24, -1);
        fn_118_407C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
