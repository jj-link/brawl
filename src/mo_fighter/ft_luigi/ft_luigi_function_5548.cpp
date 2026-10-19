#pragma force_active on
extern "C" {
void fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);
}

extern "C" void* fn_99_5548(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_614C4(storage + 0xac, destroyMember);
        if (object) fn_27_D3080(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
