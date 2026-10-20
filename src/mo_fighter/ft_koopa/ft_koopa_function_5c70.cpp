#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_3CAC(void*, short);
extern "C" void* fn_102_5CE8(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_102_5C70(void* object, short deleting) {
    if (object != 0) {
        fn_102_3CAC(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_102_5CE8(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
