#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];

public:
    virtual ~MenuObject();
};

extern "C" {
extern u8 lbl_14_data_4C4[];

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_800B8A0C(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_14_2E8(u8* object, int deleting)
{
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_14_data_4C4;

        void* entry = *reinterpret_cast<void**>(object + 0x2A1C);
        if (entry) {
            Destroy__Q34nw4r3g3d6G3dObjFv(entry);
        }

        u8* cursor = object;
        for (int i = 0; i < 0x12; ++i, cursor += 4) {
            entry = *reinterpret_cast<void**>(cursor + 0x1BC);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = object;
        for (int i = 0; i < 0x5D; ++i, cursor += 4) {
            MenuObject* menuEntry =
                *reinterpret_cast<MenuObject**>(cursor + 0x48);
            if (menuEntry) {
                delete menuEntry;
            }
        }

        entry = *reinterpret_cast<void**>(object + 0x24CC);
        if (entry) {
            fn_800B8A0C(entry, 1);
        }

        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
