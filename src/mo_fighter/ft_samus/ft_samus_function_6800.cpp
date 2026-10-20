#pragma force_active on
extern "C" void* fn_94_4A0C(void*, short);
extern "C" void* fn_94_6878(void*, short);
extern "C" void* fn_27_CD934(void*, short);
void operator delete(void*);

extern "C" void* fn_94_6800(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_4A0C(storage + 0xAC, -1);
        fn_94_6878(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
