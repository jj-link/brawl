#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_2234(void*, short);
void* fn_100_2158(void*, short);
}

// Destroy the two embedded modules, then the base when deleting.
extern "C" void* fn_100_3898(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_2234(storage + 0x50, destroy);
        fn_100_2158(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
