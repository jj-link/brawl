#pragma force_active on
extern "C" {
void* fn_94_13610(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_94_13C3C(void*, short);
}

void operator delete(void*);

extern "C" void* fn_94_1358C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_13610(members + 0x17F80, memberDeleting);
        fn_27_C74E8(members + 0x17F70, memberDeleting);
        fn_94_13C3C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
