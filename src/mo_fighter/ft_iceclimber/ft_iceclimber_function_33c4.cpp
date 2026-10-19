#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_3430(void*, short);
extern "C" void* fn_105_4AE0(void*, short);

extern "C" void* fn_105_33C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_3430(storage + 0x3EB0, -1);
        fn_105_4AE0(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
