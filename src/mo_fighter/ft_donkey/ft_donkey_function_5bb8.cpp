#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_92_5C28(void* object, short deleting);

extern "C" void* fn_92_5BB8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, static_cast<short>(-1));
        fn_92_5C28(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
