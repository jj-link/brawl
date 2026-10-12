extern "C" void* fn_99_35B8(void*, int);

// Forward the deletion word unchanged; the destructor interprets its low half.
extern "C" void* fn_99_10C44(void* object, int deleting) {
    return fn_99_35B8(static_cast<unsigned char*>(object) - 0x40, deleting);
}
