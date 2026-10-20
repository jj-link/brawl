#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_4E038(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19D5E8(void*, short);

extern "C" void* fn_96_3F18(void* object, short deleting) {
    if (object != 0) {
        fn_27_4E038(static_cast<unsigned char*>(object) + 0x150, -1);
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0xCC, -1);
        fn_27_19D5E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
