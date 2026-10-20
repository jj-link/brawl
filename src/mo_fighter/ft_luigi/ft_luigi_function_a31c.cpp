#pragma force_active on
extern "C" {
void* fn_99_A2BC(void*, short);
void* fn_99_A184(void*, short);
}

extern "C" void* fn_99_A31C(void* object, short deleting) {
    if (object) {
        fn_99_A2BC(static_cast<unsigned char*>(object) + 0xec, -1);
        if (object) {
            fn_99_A184(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
