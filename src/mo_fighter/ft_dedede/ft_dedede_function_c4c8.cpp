void operator delete(void*);
extern "C" void* fn_117_C468(void*, short);

// soInstancePool's embedded soInstancePoolSub starts after its vtable pointer.
// Destroy that subobject without freeing it; only the outer deleting form owns
// the allocation. The REL's RTTI identifies the motion-energy pool instance.
extern "C" void* fn_117_C4C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C468(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
