#pragma force_active on
extern "C" {
void* fn_98_42F8(void*, short);
void* fn_98_6FCC(void*, short);
void* fn_27_CD934(void*, short);
}

void operator delete(void*);

extern "C" void* fn_98_6F54(void* object, int deleting) {
    if (object != 0) {
        int memberDeleting = -1;
        fn_98_42F8(static_cast<char*>(object) + 0xac, memberDeleting);
        fn_98_6FCC(static_cast<char*>(object) + 0x20, memberDeleting);
        fn_27_CD934(object, memberDeleting);
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
