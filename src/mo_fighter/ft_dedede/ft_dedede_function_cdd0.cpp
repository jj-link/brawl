void operator delete(void*);
extern "C" void* fn_117_CD74(void*, short);

// The REL's RTTI identifies this as the ground-movement energy holder.
// Its constructor places the embedded energy at +4; keep the rest opaque.
extern "C" void* fn_117_CDD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CD74(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
