#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_3BAC(void*, short);
extern "C" void* fn_115_15DDC(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_115_15E38(void* object, short deleting) {
    if (object != 0) {
        fn_115_3BAC(static_cast<unsigned char*>(object) + 0x8C, -1);
        fn_115_15DDC(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
