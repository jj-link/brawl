void operator delete(void*);
extern "C" void* fn_117_CAA4(void*, short);

// The damage soInstancePoolSub embeds its soKineticEnergyHolder at +8.
// Destroy the holder without freeing embedded storage; only the outer
// deleting form owns the allocation. Constructor and RTTI establish the offset.
extern "C" void* fn_117_CB04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CAA4(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
