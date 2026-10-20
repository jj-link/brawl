#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_102_5924(void*, short);
void* fn_102_5984(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_102_58AC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_102_5924(storage + 0x18, destroyMember);
        fn_102_5984(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
