#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];

public:
    virtual ~MenuObject();
};

extern "C" {
extern u8 lbl_28_data_230[];
extern void* g_gfSceneRoot;

void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8000D7B8(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_28_290(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_28_2D0(u8* object, int deleting)
{
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_28_data_230;

        fn_800B8EDC(
            *reinterpret_cast<void**>(object + 0x12C),
            *reinterpret_cast<void**>(object + 0x138));
        fn_800B8EDC(
            *reinterpret_cast<void**>(object + 0x12C),
            *reinterpret_cast<void**>(object + 0x134));

        if (*reinterpret_cast<void**>(object + 0x12C)) {
            fn_800B8A0C(*reinterpret_cast<void**>(object + 0x12C), 1);
            *reinterpret_cast<void**>(object + 0x12C) = 0;
        }

        u8* cursor = object;
        for (int i = 0; i < 3; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x154);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = object;
        for (int i = 0; i < 9; ++i, cursor += 4) {
            MenuObject* entry =
                *reinterpret_cast<MenuObject**>(cursor + 0x130);
            if (entry) {
                delete entry;
            }
        }

        fn_8000D7B8(g_gfSceneRoot);

        cursor = object + 0x340;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            cancelRequest__14gfFileIOHandleFv(cursor);
            free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(cursor));
            release__14gfFileIOHandleFv(cursor);
        }

        __destroy_arr(object + 0x340, __dt__14gfFileIOHandleFv, 4, 2);
        __destroy_arr(object + 0x170, fn_28_290, 0xB8, 2);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
