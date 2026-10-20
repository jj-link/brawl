#pragma force_active on
void operator delete(void*);

extern "C" void* fn_105_4060(void*, short);
extern "C" void* fn_105_6594(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_105_651C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_4060(storage + 0x85C, -1);
        fn_105_6594(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
