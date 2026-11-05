#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_10_data_C10[];

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_10_19914(u8* self, int deleting)
{
    if (self) {
        *reinterpret_cast<void**>(self + 0x3C) = lbl_10_data_C10;

        void* entry = *reinterpret_cast<void**>(self + 0x44);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        }

        entry = *reinterpret_cast<void**>(self + 0x48);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        }

        entry = *reinterpret_cast<void**>(self + 0x4C);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        }

        entry = *reinterpret_cast<void**>(self + 0x7C);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        }

        u8* cursor = self;
        for (int i = 0; i < 0xB; ++i, cursor += 4) {
            entry = *reinterpret_cast<void**>(cursor + 0x50);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
}
