#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_7CD0(void* object, short deleting);
extern "C" void* fn_93_5F68(void* object, short n);

extern "C" void* fn_93_7D2C(void* object, short deleting) {
    if (object != 0) {
        fn_93_7CD0(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_93_5F68(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
