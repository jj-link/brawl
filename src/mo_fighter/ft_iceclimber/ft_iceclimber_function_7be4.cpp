#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_4060(void* object, short deleting);
extern "C" void* fn_105_7C5C(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_105_7BE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_4060(storage + 0xAC, -1);
        fn_105_7C5C(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
