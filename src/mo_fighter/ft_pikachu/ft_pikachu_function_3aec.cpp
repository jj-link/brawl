#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_2214(void*, short);
void* fn_98_2138(void*, short);
}

extern "C" void* fn_98_3AEC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_98_2214(static_cast<char*>(object) + 0x50, memberDeleting);
        fn_98_2138(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
