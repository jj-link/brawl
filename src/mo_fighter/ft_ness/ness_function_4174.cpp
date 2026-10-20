#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_41FC(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_101_4174(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_41FC(members + 0x8C, memberDeleting);
        void* ptr = static_cast<void*>(members + 0x20);
        if (ptr != 0 && ptr != 0 && ptr != 0) {
            fn_27_1A1E70(ptr, memberDeleting);
        }
        fn_27_CD934(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
