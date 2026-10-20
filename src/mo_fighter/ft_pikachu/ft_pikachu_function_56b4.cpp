#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_A4E8(void*, short);
void* fn_98_572C(void*, short);
void* fn_98_579C(void*, short);
}

extern "C" void* fn_98_56B4(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_98_A4E8(static_cast<char*>(object) + 0xE0, memberDeleting);
        fn_98_572C(static_cast<char*>(object) + 0x30, memberDeleting);
        fn_98_579C(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
