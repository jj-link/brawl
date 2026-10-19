#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_1EF4(void*, short);
void* fn_98_4088(void*, short);
}

extern "C" void* fn_98_579C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = 0;
        fn_98_1EF4(static_cast<char*>(object) + 0x20, memberDeleting);
        fn_98_4088(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
