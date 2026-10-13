void operator delete(void*);
extern "C" void* fn_117_CC3C(void*, short);

// The wind-energy pool subobject embeds its base eight bytes into the object.
// Destroy that base in place; only a positive outer flag releases the storage.
extern "C" void* fn_117_CC9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CC3C(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
