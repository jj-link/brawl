#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3DEC(void*, short);
void* fn_100_5108(void*, short);
void* fn_27_19E99C(void*, short);
}

// Destroy the two embedded members, then the object itself when deleting > 0.
extern "C" void* fn_100_5090(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3DEC(storage + 0x85c, destroy);
        fn_100_5108(storage + 0x19c, destroy);
        fn_27_19E99C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
