#pragma force_active on
typedef unsigned char u8;

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_20_4760(u8* object) {
    void* entry = *reinterpret_cast<void**>(object + 0x2C);
    if (entry) {
        Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        *reinterpret_cast<void**>(object + 0x2C) = 0;
    }

    entry = *reinterpret_cast<void**>(object + 0x30);
    if (entry) {
        Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        *reinterpret_cast<void**>(object + 0x30) = 0;
    }

    entry = *reinterpret_cast<void**>(object + 0x28);
    if (entry) {
        Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        *reinterpret_cast<void**>(object + 0x28) = 0;
    }
}
}
