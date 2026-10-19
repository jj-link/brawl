#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_2268(void*, short);
extern "C" void* fn_105_218C(void*, short);

extern "C" void* fn_105_3814(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_2268(storage + 0x50, -1);
        fn_105_218C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
