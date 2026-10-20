#pragma force_active on
extern "C" {
void* fn_94_1FF4(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_94_28AC(void*, short);
void __dl__FPv(void*);
}

void operator delete(void*);

extern "C" void* fn_94_1F70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_1FF4(members + 0x23E7C, memberDeleting);
        fn_27_C74E8(members + 0x23E6C, memberDeleting);
        fn_94_28AC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
