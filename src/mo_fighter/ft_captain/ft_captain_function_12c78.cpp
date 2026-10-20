#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_100_4480(void*, short);
void* fn_100_44DC(void*, short);
}

extern "C" void* fn_100_12C78(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_13C90(storage + 0xd8, destroy);
        fn_27_21038(storage + 0xc4, destroy);
        fn_100_4480(storage + 0x88, destroy);
        fn_100_44DC(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
