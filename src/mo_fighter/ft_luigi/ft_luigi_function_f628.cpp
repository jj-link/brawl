extern "C" {
void* fn_99_1E9C(void*, short);
void* fn_99_1E40(void*, short);
}

extern "C" void* fn_99_F628(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_99_1E9C(storage + 0x20, destroyMember);
        if (object) fn_99_1E40(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
