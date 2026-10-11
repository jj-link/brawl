extern "C" int fn_118_13C58(void*);
// The adjustor forwards the flag register unchanged; the destructor sign-extends
// its low 16 bits. A word-sized declaration avoids an extra caller conversion.
extern "C" void* fn_118_13BFC(void*, int);

// The secondary interface begins four bytes after the complete scalar object.
extern "C" int fn_118_13F44(void* interface) {
    return fn_118_13C58(static_cast<unsigned char*>(interface) - 4);
}
extern "C" void* fn_118_13F4C(void* interface, int deleting) {
    return fn_118_13BFC(static_cast<unsigned char*>(interface) - 4, deleting);
}
