#pragma force_active on
void operator delete(void*);

extern "C" void fn_105_3C24(void*, short);
extern "C" void* fn_105_4100(void* object, short deleting) {
    if (object != 0) {
        fn_105_3C24(static_cast<unsigned char*>(object) + 0x14, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
