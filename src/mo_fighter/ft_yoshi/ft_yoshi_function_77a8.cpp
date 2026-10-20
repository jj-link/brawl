#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_95_7820(void* object, short deleting);
void* fn_95_7880(void* object, short deleting);
}

extern "C" void* fn_95_77A8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_95_7820(storage + 0x18, destroyMember);
        fn_95_7880(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
