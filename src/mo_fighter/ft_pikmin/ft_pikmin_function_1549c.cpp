#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_113_3384(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_113_33F0(void*, short);
extern "C" void* fn_113_344C(void*, short);
void operator delete(void*);

extern "C" void* fn_113_1549C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x110, -1);
        fn_113_3384(storage + 0xD4, -1);
        fn_27_21038(storage + 0xC4, -1);
        fn_113_33F0(storage + 0x88, -1);
        fn_113_344C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
