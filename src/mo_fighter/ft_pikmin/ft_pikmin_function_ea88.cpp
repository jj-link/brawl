#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_EA28(void* object, short deleting);
extern "C" void* fn_113_E8F0(void* object, short deleting);

extern "C" void* fn_113_EA88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_EA28(storage + 0x17c, -1);
        if (object != 0) {
            fn_113_E8F0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
