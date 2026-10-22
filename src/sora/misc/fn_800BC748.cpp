#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

class MenuObject {
    u8 padding[0x5C];
public:
    virtual void method(int);
};

extern "C" {
extern u8 lbl_80456CAC[];
extern void* g_GameGlobal;
extern void* g_sndSystem;

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_800B8A0C(void*, int);
void freeGroup__9sndSystemFii(void*, int, int);
void exit__6gfTaskFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_800BA484(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_800BC748(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_80456CAC;
        *(char*)((char*)(*(void**)((char*)g_GameGlobal + 0x24)) + 0x15A8) = (char)*(s32*)(object + 0x12B4);

        u8* cursor = object;
        for (unsigned int i = 0; i < 0x84; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0xB64);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
                *reinterpret_cast<void**>(cursor + 0xB64) = 0;
            }
        }

        cursor = object;
        for (unsigned int i = 0; i < 0x299; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0x100);
            if (entry) {
                if (entry) {
                    entry->method(1);
                }
                *reinterpret_cast<void**>(cursor + 0x100) = 0;
            }
        }

        if (*(void**)(object + 0x1300)) {
            free__13gfHeapManagerFPv(*(void**)(object + 0x1300));
            *(void**)(object + 0x1300) = 0;
        }

        if (*(void**)(object + 0x12F4)) {
            __dt__9gfArchiveFv(*(void**)(object + 0x12F4), 1);
            *(void**)(object + 0x12F4) = 0;
        }

        if (*(void**)(object + 0x12F8)) {
            __dt__9gfArchiveFv(*(void**)(object + 0x12F8), 1);
            *(void**)(object + 0x12F8) = 0;
        }

        fn_800B8A0C(*(void**)(object + 0xD78), 1);
        freeGroup__9sndSystemFii(g_sndSystem, *(s32*)(object + 0xFC), 1);
        exit__6gfTaskFv(*(void**)(object + 0xD74));
        *(void**)(object + 0xD74) = 0;
        exit__6gfTaskFv(*(void**)(object + 0x40));
        *(void**)(object + 0x40) = 0;
        __dt__14gfFileIOHandleFv(object + 0x12FC, -1);
        fn_800BA484(object + 0xE84, -1);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
