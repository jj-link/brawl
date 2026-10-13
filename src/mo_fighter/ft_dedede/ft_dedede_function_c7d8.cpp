void operator delete(void*);
extern "C" void* fn_117_C778(void*, short);

// The controller soInstancePoolSub contains its soKineticEnergyHolder at +8.
// Destroy the embedded holder without freeing it; only the outer deleting
// form owns the allocation. The REL's constructor and RTTI establish this offset.
extern "C" void* fn_117_C7D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C778(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
