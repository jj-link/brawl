#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_109_6014(void*, short);
void* fn_109_6074(void*, short);
}

extern "C" void* fn_109_5F9C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_109_6014(storage + 0x18, destroyMember);
        fn_109_6074(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
