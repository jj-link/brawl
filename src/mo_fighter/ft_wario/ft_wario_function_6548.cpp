#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_110_65C0(void* object, short deleting);
void* fn_110_6620(void* p, short n);
}

extern "C" void* fn_110_6548(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_110_65C0(storage + 0x18, destroyMember);
        fn_110_6620(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
