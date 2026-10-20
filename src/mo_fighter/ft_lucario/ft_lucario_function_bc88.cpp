#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_BC28(void*, short);
extern "C" void* fn_118_BAF0(void*, short);

extern "C" void* fn_118_BC88(void* object, short deleting) {
    if (object != 0) {
        fn_118_BC28(static_cast<unsigned char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_118_BAF0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
