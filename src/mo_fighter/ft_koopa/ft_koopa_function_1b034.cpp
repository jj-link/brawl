#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_3CAC(void* object, short deleting);
extern "C" void* fn_102_1B0AC(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_102_1B034(void* object, short deleting) {
    if (object != 0) {
        fn_102_3CAC(static_cast<unsigned char*>(object) + 0x6C, -1);
        fn_102_1B0AC(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
