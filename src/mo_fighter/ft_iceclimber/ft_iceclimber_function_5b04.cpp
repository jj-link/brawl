#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_5B74(void*, short);
extern "C" void* fn_105_5F0C(void*, short);

extern "C" void* fn_105_5B04(void* object, short deleting) {
    if (object != 0) {
        fn_105_5B74(static_cast<unsigned char*>(object) + 0x202C, -1);
        fn_105_5F0C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
