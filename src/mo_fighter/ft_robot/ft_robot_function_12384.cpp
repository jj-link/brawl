#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_3E58(void*, short);
extern "C" void* fn_120_12328(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_120_12384(void* object, short deleting) {
    if (object != 0) {
        fn_120_3E58(static_cast<unsigned char*>(object) + 0x6C, -1);
        fn_120_12328(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
