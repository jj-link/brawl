#pragma force_active on
typedef unsigned char u8;

class AdvStageObj {
    u8 pad[0x5C];
public:
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_40_data_17CFC[];
extern void* g_gfSceneRoot;

void fn_8000E590(u8* base, int index, unsigned val);
void fn_800B8A0C(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8000D7B8(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void free__13gfHeapManagerFPv(void*);
void fn_40_3E194(void*, int);
void fn_40_3E220(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_40_3E260(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_40_data_17CFC;
        fn_8000E590((u8*)g_gfSceneRoot, 8, 0);

        u8* cursor = object;
        for (int i = 0; i < 0xC; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x934);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = object;
        for (int i = 0; i < 0x89; ++i, cursor += 4) {
            AdvStageObj* entry = *reinterpret_cast<AdvStageObj**>(cursor + 0x710);
            if (entry) {
                if (entry) {
                    entry->f0(1);
                }
            }
        }

        if (*(void**)(object + 0x964)) {
            free__13gfHeapManagerFPv(*(void**)((u8*)*(void**)(object + 0x964) + 4));
            fn_800B8A0C(*(void**)(object + 0x964), 1);
        }

        if (*(void**)(object + 0x700)) {
            free__13gfHeapManagerFPv(*(void**)(object + 0x700));
        }
        if (*(void**)(object + 0x704)) {
            free__13gfHeapManagerFPv(*(void**)(object + 0x704));
        }
        if (*(void**)(object + 0x708)) {
            free__13gfHeapManagerFPv(*(void**)(object + 0x708));
        }

        if (*(u8*)(object + 0xC2B)) {
            fn_8000D7B8(g_gfSceneRoot);
        }

        if (*(void**)(object + 0x70C)) {
            free__13gfHeapManagerFPv(*(void**)(object + 0x70C));
        }

        cursor = object + 0xC40;
        for (int i = 0; i < 5; ++i, cursor += 4) {
            cancelRequest__14gfFileIOHandleFv(cursor);
        }

        __destroy_arr(object + 0xC40, fn_40_3E194, 4, 5);
        __destroy_arr(object + 0x970, fn_40_3E220, 0x150, 2);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}