#pragma force_active on
extern "C" {
void* fn_108_3D98(void* object, short deleting);
void* fn_108_65F0(void* object, short deleting);
void* fn_27_19E99C(void* member, short deleteFlag);
void __dl__FPv(void*);
}

extern "C" void* fn_108_6578(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_3D98(storage + 0x85C, -1);
        fn_108_65F0(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
