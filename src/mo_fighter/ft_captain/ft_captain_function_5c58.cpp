#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_150488(void*, short);
void* fn_100_5CD8(void*, short);
void* fn_27_199A54(void*, short);
}

// Complete-object destructor for the Captain fighter-module member at +0x3F8C
// (see the fn_100_5C58 call in ft_captain_function_28ac.cpp). Destroys the
// embedded members at +0x5B8 and +0x584 in reverse construction order via
// their module destructors, then the object itself behind its own null guard
// (the guard is preserved verbatim from the original), and finally releases
// the storage when the deleting form was requested.
extern "C" void* fn_100_5C58(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_150488(storage + 0x5B8, destroy);
        fn_100_5CD8(storage + 0x584, destroy);
        if (object != 0) {
            fn_27_199A54(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
