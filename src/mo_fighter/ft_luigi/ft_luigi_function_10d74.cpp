extern "C" void* fn_99_35B8(void*, int);

// Recover the embedded object 0x88 bytes back; forward the deletion word unchanged.
extern "C" void* fn_99_10D74(void* object, int deleting) {
    return fn_99_35B8(static_cast<unsigned char*>(object) - 0x88, deleting);
}
