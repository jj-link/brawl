#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_105_2100(void*, short);
void* fn_105_22C4(void*, short);
void* fn_105_238C(void*, short);
void* fn_105_2418(void*, short);
void* fn_105_24A4(void*, short);
void* fn_105_2530(void*, short);
void* fn_105_25BC(void*, short);
void* fn_105_2648(void*, short);
void* fn_105_26D4(void*, short);
void* fn_105_2760(void*, short);
void* fn_105_27EC(void*, short);
}
extern "C" void* fn_105_2028(void* object, short deleting) {
    if (object) {
        unsigned char* p = (unsigned char*)object;
        fn_105_2100(p + 0x14C0, -1);
        fn_105_22C4(p + 0x139C, -1);
        fn_105_238C(p + 0x1270, -1);
        fn_105_2418(p + 0x1144, -1);
        fn_105_24A4(p + 0x1018, -1);
        fn_105_2530(p + 0xEEC, -1);
        fn_105_25BC(p + 0xDC0, -1);
        fn_105_2648(p + 0xC94, -1);
        fn_105_26D4(p + 0xB68, -1);
        fn_105_2760(p + 0xA3C, -1);
        fn_105_27EC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}