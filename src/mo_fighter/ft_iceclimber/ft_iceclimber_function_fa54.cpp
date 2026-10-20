#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_F9F4(void* object, short deleting);
extern "C" void* fn_105_F8C4(void* object, short deleting);

extern "C" void* fn_105_FA54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_F9F4(storage + 0x94, -1);
        if (object != 0) {
            fn_105_F8C4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
