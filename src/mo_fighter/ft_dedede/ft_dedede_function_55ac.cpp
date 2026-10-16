void operator delete(void*);

extern "C" {
void* fn_27_150488(void*, short);
void* fn_117_562C(void*, short);
void* fn_27_199A54(void*, short);
}

// Complete-object destructor for the fighter-module member at +0x407C
// (see the fn_117_55AC call in ft_dedede_function_2944.cpp). Destroys the
// embedded members at +0x5B8 and +0x584 in reverse construction order via
// their sora_melee/module destructors, then the object itself behind its own
// null guard (the guard is preserved verbatim from the original), and
// finally releases the storage when the deleting form was requested.
extern "C" void* fn_117_55AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_150488(storage + 0x5B8, -1);
        fn_117_562C(storage + 0x584, -1);
        if (object != 0) {
            fn_27_199A54(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
