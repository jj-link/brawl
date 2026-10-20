#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_3F8C(void*, short);
extern "C" void* fn_92_6A1C(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_92_69A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_3F8C(storage + 0xAC, -1);
        fn_92_6A1C(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
