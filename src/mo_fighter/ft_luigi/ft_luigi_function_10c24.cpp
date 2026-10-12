extern "C" void* fn_99_108D4(void*, int);

// Adjust the secondary-base receiver to the complete singleton object.
extern "C" void* fn_99_10C24(void* object, int deleting) {
    return fn_99_108D4(static_cast<char*>(object) - 4, deleting);
}
