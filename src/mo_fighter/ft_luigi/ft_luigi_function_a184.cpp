#pragma force_active on
extern "C" {
void* fn_99_A124(void*, short);
void* fn_99_9FF4(void*, short);
}

// Destroy the embedded module at +0x94, then run the base-class cleanup.
// Only positive deleting values free the object.
extern "C" void* fn_99_A184(void* object, short deleting) {
    if (object) {
        fn_99_A124(static_cast<unsigned char*>(object) + 0x94, -1);
        if (object) {
            fn_99_9FF4(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
