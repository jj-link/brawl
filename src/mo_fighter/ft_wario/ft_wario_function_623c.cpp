#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_4E038(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CD4A4(void*, short);

extern "C" void* fn_110_623C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_4E038(storage + 0xF0, -1);
        fn_27_4CAA0(storage + 0x6C, -1);
        fn_27_CD4A4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
