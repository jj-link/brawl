#pragma force_active on
extern "C" void* fn_120_1F80(void*, short);
extern "C" void* fn_120_1F24(void*, short);

extern "C" void* fn_120_3B90(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_120_1F80(storage + 0x20, destroyMember);
        if (object) fn_120_1F24(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
