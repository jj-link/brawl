#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_108_78F4(void*, short);
void* fn_108_7954(void*, short);
}

extern "C" void* fn_108_787C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_108_78F4(storage + 0x18, destroyMember);
        fn_108_7954(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
