#pragma force_active on
extern "C" {
void* fn_120_1F80(void*, short);
void* fn_120_1F24(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_12CAC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = 0;
        fn_120_1F80(storage + 0x20, destroyMember);
        if (object) fn_120_1F24(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
