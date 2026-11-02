#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

class MenuObject {
    u8 padding[0x5C];
public:
    virtual void method(int);
};

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);

void* fn_3_468(u8* object, int deleting) {
    if (object) {
        Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)object);
        *(void**)object = 0;

        u8* cursor = object;
        for (unsigned int i = 0; i < 0x5E; ++i, cursor += 4) {
            MenuObject* entry = *(MenuObject**)(cursor + 4);
            if (entry) {
                if (entry) {
                    entry->method(1);
                }
                *(void**)(cursor + 4) = 0;
            }
        }

        cursor = object;
        for (unsigned int i = 0; i < 0x60; ++i, cursor += 4) {
            MenuObject* entry = *(MenuObject**)(cursor + 0xF50);
            if (entry) {
                if (entry) {
                    entry->method(1);
                }
                *(void**)(cursor + 0xF50) = 0;
            }
        }

        __dt__9gfArchiveFv(*(void**)(object + 0x10E4), 1);

        if (*(s32*)(object + 0x10DC) != 0) {
            free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x10E8));
            release__14gfFileIOHandleFv(object + 0x10E8);
        }

        cursor = object + 4;
        for (unsigned int i = 1; i < 0x3F; ++i, cursor += 4) {
            void* entry = *(void**)(cursor + 0x1F8);
            if (entry) {
                free__13gfHeapManagerFPv(entry);
                *(void**)(cursor + 0x1F8) = 0;
            }
        }

        cursor = object + 4;
        for (unsigned int i = 1; i < 0x1F; ++i, cursor += 4) {
            void* entry = *(void**)(cursor + 0x17C);
            if (entry) {
                free__13gfHeapManagerFPv(entry);
                *(void**)(cursor + 0x17C) = 0;
            }
        }

        exit__6gfTaskFv(*(void**)(object + 0x2F4));
        *(void**)(object + 0x2F4) = 0;
        fn_800B8A0C(*(void**)(object + 0x10D4), 1);
        __dt__14gfFileIOHandleFv(object + 0x10E8, -1);

        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
