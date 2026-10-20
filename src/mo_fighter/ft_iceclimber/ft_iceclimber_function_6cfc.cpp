#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_105_6D74(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_105_6CFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0xF0, -1);
        if (object != 0) {
            fn_105_6D74(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
