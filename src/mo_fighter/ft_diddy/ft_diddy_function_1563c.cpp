#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_3BAC(void* object, short deleting);
extern "C" void* fn_115_155E0(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_115_1563C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3BAC(storage + 0x6C, -1);
        fn_115_155E0(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
