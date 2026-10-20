#pragma force_active on
void operator delete(void*);
extern "C" void fn_105_100AC(void* object, short deleting);
extern "C" void* fn_105_101E0(void* object, short deleting);

extern "C" void* fn_105_10240(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_101E0(storage + 0x204, -1);
        if (object != 0) {
            fn_105_100AC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
