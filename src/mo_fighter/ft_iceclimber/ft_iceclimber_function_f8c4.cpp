#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_F864(void*, short);
extern "C" void* fn_105_F744(void*, short);

extern "C" void* fn_105_F8C4(void* object, short deleting) {
    if (object != 0) {
        fn_105_F864(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_105_F744(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
