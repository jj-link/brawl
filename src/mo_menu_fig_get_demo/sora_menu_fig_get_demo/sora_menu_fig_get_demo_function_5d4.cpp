#pragma force_active on
typedef unsigned char u8;

class MenuFigObject {
    u8 padding[0x5C];

public:
    virtual ~MenuFigObject();
};

extern "C" {
extern u8 lbl_26_data_1C0[];
extern void* g_gfSceneRoot;

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8000D7B8(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__14gfFileIOHandleFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_26_5D4(u8* object, int deleting)
{
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_26_data_1C0;

        u8* cursor = object;
        for (int i = 0; i < 3; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x1F4);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = object;
        for (int i = 0; i < *reinterpret_cast<int*>(object + 0x1DC); cursor += 4, ++i) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x204);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        if (*reinterpret_cast<void**>(object + 0x200)) {
            Destroy__Q34nw4r3g3d6G3dObjFv(*reinterpret_cast<void**>(object + 0x200));
        }

        cursor = object;
        for (int i = 0; i < 0xCC; ++i, cursor += 4) {
            MenuFigObject* entry = *reinterpret_cast<MenuFigObject**>(cursor + 0x6CC);
            if (entry) {
                delete entry;
            }
        }

        {
            MenuFigObject* entry = *reinterpret_cast<MenuFigObject**>(object + 0x1E8);
            if (entry) {
                delete entry;
            }
        }
        {
            MenuFigObject* entry = *reinterpret_cast<MenuFigObject**>(object + 0x1EC);
            if (entry) {
                delete entry;
            }
        }

        cancelRequest__14gfFileIOHandleFv(object + 0x9FC);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x9FC));
        release__14gfFileIOHandleFv(object + 0x9FC);

        cancelRequest__14gfFileIOHandleFv(object + 0xD1C);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0xD1C));
        release__14gfFileIOHandleFv(object + 0xD1C);

        cancelRequest__14gfFileIOHandleFv(object + 0x103C);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x103C));
        release__14gfFileIOHandleFv(object + 0x103C);

        cancelRequest__14gfFileIOHandleFv(object + 0x11CC);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x11CC));
        release__14gfFileIOHandleFv(object + 0x11CC);

        __dt__9gfArchiveFv(*reinterpret_cast<void**>(object + 0x135C), 1);
        *reinterpret_cast<void**>(object + 0x135C) = 0;
        fn_8000D7B8(g_gfSceneRoot);

        __destroy_arr(object + 0x9FC, __dt__14gfFileIOHandleFv, 4, 0x258);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
