extern "C" void* fn_99_ECE8(void*, int);

// Forward the deletion word unchanged; the destructor reads its signed low half.
extern "C" void* fn_99_10C34(void* object, int deleting) {
    return fn_99_ECE8(static_cast<unsigned char*>(object) - 0x90, deleting);
}
