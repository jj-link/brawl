#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_21208(void* object, short deleting);
extern "C" void* fn_117_210E8(void* object, short deleting);

extern "C" void* fn_117_21268(void* object, short deleting) {
    if (object != 0) {
        fn_117_21208(static_cast<unsigned char*>(object) + 0x44, -1);
        fn_117_210E8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
