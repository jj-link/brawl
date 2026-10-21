#pragma force_active on
// Free the given pointer's resource (if any), returning the original pointer.
// The triple comparison against 0 compiles to the chain of three beq branches
// the original emits; the call site always passes the pointer with a 0 flag.
extern "C" void fn_8019D88C(void*, int);

extern "C" void* fn_80198944(void* p) {
    if (p != 0 && p != 0 && p != 0) {
        fn_8019D88C(p, 0);
    }
    return p;
}
