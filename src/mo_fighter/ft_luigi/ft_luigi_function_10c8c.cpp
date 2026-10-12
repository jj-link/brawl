extern "C" void* fn_99_35B8(void*, int);

// Recover the complete object; forward the deletion word without narrowing.
extern "C" void* fn_99_10C8C(void* object, int deleting) {
    return fn_99_35B8(static_cast<unsigned char*>(object) - 0x90, deleting);
}
