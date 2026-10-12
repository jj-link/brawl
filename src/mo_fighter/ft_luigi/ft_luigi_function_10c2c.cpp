// The adjustment entry forwards the destructor flag word unchanged.
extern "C" void* fn_99_ECE8(void*, int);

extern "C" void* fn_99_10C2C(void* object, int deleting) {
    return fn_99_ECE8(static_cast<unsigned char*>(object) - 0x40, deleting);
}
