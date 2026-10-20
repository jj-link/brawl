#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_119_11A98(void* p, short flag);
void* fn_119_11A58(void* p, short flag);
void __dl__FPv(void*);
}

extern "C" void* fn_119_11AF4(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x20, destroyMember);
        fn_119_11A98(storage + 0x10, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_119_11A58(object, destroyBase);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
