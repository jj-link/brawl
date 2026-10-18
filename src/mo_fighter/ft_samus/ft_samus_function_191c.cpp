#pragma force_active on
extern "C" {
void* fn_94_19BC(void*, short);
void* fn_94_1D9C(void*, short);
void* fn_94_1E38(void*, short);
void* fn_94_1F70(void*, short);
void* fn_27_125E20(void*, short);
}

extern "C" void* fn_94_191C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_19BC(members + 0x25B50, memberDeleting);
        fn_94_1D9C(members + 0x25698, memberDeleting);
        fn_94_1E38(members + 0x2565C, memberDeleting);
        fn_94_1F70(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
