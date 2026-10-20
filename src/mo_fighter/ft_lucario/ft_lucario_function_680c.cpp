#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_3EB4(void*, short);
extern "C" void* fn_118_6884(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_118_680C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_3EB4(storage + 0xAC, -1);
        fn_118_6884(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
