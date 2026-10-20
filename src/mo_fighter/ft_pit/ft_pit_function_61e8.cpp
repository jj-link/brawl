#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void* object, short value);
extern "C" void fn_112_6260(void* object, short deleting);

extern "C" void* fn_112_61E8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x190, -1);
        if (object != 0) {
            fn_112_6260(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
