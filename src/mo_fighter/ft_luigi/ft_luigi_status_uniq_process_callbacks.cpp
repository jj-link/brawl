// Shared Luigi status-process virtual callbacks. Unused ABI arguments remain
// untouched; the deleting destructor returns the original process pointer.
extern "C" {
bool fn_99_CD44(void*) { return true; }
void fn_99_CD4C(void*) {}
bool fn_99_CD50(void*) { return false; }
void fn_99_CD58(void*) {}
bool fn_99_CD5C(void*) { return false; }
void fn_99_CD64(void*) {}
void fn_99_CD68(void*) {}
void fn_99_CD6C(void*) {}
void fn_99_CD70(void*) {}
void fn_99_CD74(void*) {}
void fn_99_CD78(void*) {}
void* fn_99_CD7C(void* process, short deleting) {
    if (process && deleting > 0) operator delete(process);
    return process;
}
void fn_99_CDBC(void*) {}
}
