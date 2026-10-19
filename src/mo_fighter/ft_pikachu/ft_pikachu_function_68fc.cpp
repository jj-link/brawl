#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_27_4B53C(void*, short);
void fn_27_19C45C(void*, short);

void* fn_98_68FC(void* object, int deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_4B53C(static_cast<char*>(object) + 0x17C, memberDeleting);
        fn_27_19C45C(object, memberDeleting);
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
}
