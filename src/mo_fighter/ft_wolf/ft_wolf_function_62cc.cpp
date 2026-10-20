#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_3DF0(void*, short);
extern "C" void* fn_125_6344(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_125_62CC(void* object, short deleting) {
    if (object != 0) {
        fn_125_3DF0(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_125_6344(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
