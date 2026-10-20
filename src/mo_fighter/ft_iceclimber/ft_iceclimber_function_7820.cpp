#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_105_7898(void*, short);
void* fn_105_78F8(void*, short);
}

extern "C" void* fn_105_7820(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_105_7898(storage + 0x18, destroyMember);
        fn_105_78F8(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
