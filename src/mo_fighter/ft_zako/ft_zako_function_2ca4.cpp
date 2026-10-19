#pragma force_active on
extern "C" {
void fn_27_1990E8(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_2CA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_1990E8(storage + 0x214, destroyMember);
        fn_27_199214(storage + 0x88, destroyMember);
        fn_27_A78FC(storage + 0x6c, destroyMember);
        fn_27_14E050(storage + 0x4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
