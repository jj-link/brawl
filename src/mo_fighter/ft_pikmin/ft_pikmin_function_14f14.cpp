#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2D0C(void*, short);
extern "C" void* fn_113_14F8C(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_113_14F14(void* object, short deleting) {
    if (object != 0) {
        short m = -1;
        fn_113_2D0C(static_cast<unsigned char*>(object) + 0x12C, m);
        fn_113_14F8C(static_cast<unsigned char*>(object) + 0x20, m);
        fn_27_CD934(object, m);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
