#pragma force_active on
extern "C" {
void* fn_115_1F4C(void*, short);
void* fn_115_1EF0(void*, short);
}

extern "C" void* fn_115_1ADF8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_115_1F4C(storage + 0x20, destroyMember);
        if (object) fn_115_1EF0(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
