#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_63E4(void*, short);
void* fn_98_44C0(void*, short);

void* fn_98_6378(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_63E4(static_cast<char*>(object) + 0x24, memberDeleting);
        fn_98_44C0(object, memberDeleting);
        if (static_cast<short>(deleting) > 0)
            operator delete(object);
    }
    return object;
}
}
