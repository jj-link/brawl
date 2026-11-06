#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class MenuObject {
    u8 padding[0x5C];
public:
    virtual void method(int);
};

extern "C" {
extern char lbl_2_data_4A6C[];

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void fn_2_36940(void*, int);
void fn_2_36D8C(char* base, int a, int b);

void* fn_2_37568(char* object, int deleting) {
    if (object) {
        char* cursor;
        u32 i;
        u32 i2;
        u32 i3;

        *reinterpret_cast<void**>(object + 0x3C) = lbl_2_data_4A6C;

        for (i2 = 0, cursor = object; i2 < *(u32*)(object + 0x2840); cursor += 8, ++i2) {
            fn_2_36D8C(object + 0x1A0,
                       *(int*)(cursor + 0x17A0),
                       *(int*)(cursor + 0x17A4));
        }

        cursor = object;
        for (i = 0; i < 0xC; cursor += 4, ++i) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x164);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
                *reinterpret_cast<void**>(cursor + 0x164) = 0;
            }
        }

        cursor = object;
        for (i3 = 0; i3 < 0x1B; cursor += 4, ++i3) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0xF8);
            if (entry) {
                if (entry) {
                    entry->method(1);
                }
                *reinterpret_cast<void**>(cursor + 0xF8) = 0;
            }
        }

        __dt__9gfArchiveFv(*reinterpret_cast<void**>(object + 0x2844), 1);
        fn_800B8A0C(*reinterpret_cast<void**>(object + 0x198), 1);
        exit__6gfTaskFv(*reinterpret_cast<void**>(object + 0x194));
        *reinterpret_cast<void**>(object + 0x194) = 0;
        exit__6gfTaskFv(*reinterpret_cast<void**>(object + 0x40));
        *reinterpret_cast<void**>(object + 0x40) = 0;
        fn_2_36940(object + 0x1A0, -1);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
