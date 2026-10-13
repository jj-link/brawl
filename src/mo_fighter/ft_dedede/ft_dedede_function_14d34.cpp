void operator delete(void*);
extern "C" void* fn_117_14CC8(void*, short);
extern "C" void* fn_117_14C3C(void*, short);
extern "C" void* fn_117_14BB0(void*, short);
extern "C" void* fn_117_14B24(void*, short);
extern "C" void* fn_117_14A98(void*, short);

// Destroy the five embedded elements in reverse order. Their negative flags
// retain element storage; only the outer positive flag frees the allocation.
extern "C" void* fn_117_14D34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_14CC8(storage + 0x4B0, -1);
        fn_117_14C3C(storage + 0x384, -1);
        fn_117_14BB0(storage + 0x258, -1);
        fn_117_14B24(storage + 0x12C, -1);
        fn_117_14A98(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
