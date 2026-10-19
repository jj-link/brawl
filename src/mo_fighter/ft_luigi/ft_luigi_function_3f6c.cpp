#pragma force_active on
extern "C" {
void* fn_99_1E40(void*, short);
void* fn_99_1E9C(void*, short);
}

extern "C" void* fn_99_3F6C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_99_1E40(storage + 0x14, destroyMember);
        fn_99_1E9C(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
