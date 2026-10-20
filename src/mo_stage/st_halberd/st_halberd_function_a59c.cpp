#pragma force_active on
// st_halberd: fn_57_A59C — float array accessor.
//
// Original assembly (16 bytes):
//   lwz   r3, 0x5b0(r3)     ; load float array pointer from offset 0x5b0 of the object
//   slwi  r0, r4, 2         ; index * 4
//   lfsx  f1, r3, r0        ; load float at arrayPtr[index]
//   blr
//
// The object at offset 0x5b0 holds a pointer to a float array (soGeneralWorkSimple's
// m_floatWorks), so the returned element is read via that pointer, not inline storage.

extern "C" float fn_57_A59C(const void* work, int index) {
    const float* const* slot = (const float* const*)((const char*)work + 0x5b0);
    return (*slot)[index];
}
