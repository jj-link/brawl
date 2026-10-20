#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_115_15784(void*, short);
void* fn_115_3D54(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_157E0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x20, destroyMember);
        fn_115_15784(storage + 0x10, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_115_3D54(object, destroyBase);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
