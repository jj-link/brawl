#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_1F48(void* p, short flag);
extern "C" void* fn_105_3D9C(void* object, short deleting);

extern "C" void* fn_105_5290(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short zero = 0;
        fn_105_1F48(storage + 0x20, zero);
        fn_105_3D9C(object, zero);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
