#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_3E58(void*, short);
extern "C" void* fn_120_5794(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_120_571C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_3E58(storage + 0xAC, -1);
        fn_120_5794(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
