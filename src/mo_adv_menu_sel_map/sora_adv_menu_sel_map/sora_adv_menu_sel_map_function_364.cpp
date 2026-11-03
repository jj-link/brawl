#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    char pad[0x5C];

public:
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_31_data_26C[];
extern void* g_gfSceneRoot;

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_800B8A0C(void*, int);
void fn_8000D7B8(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_1_406C(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
void fn_31_324(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);

void* fn_31_364(u8* object, int deleting) {
    void* h = 0;
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_31_data_26C;

        u8* cursor = object;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x48C);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = object;
        for (int i = 0; i < 0xB2; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0x1C4);
            if (entry) {
                entry->f0(1);
            }
        }

        fn_8000D7B8(g_gfSceneRoot);

        void* ptr = *reinterpret_cast<void**>(object + 0x4A0);
        if (ptr) {
            Destroy__Q34nw4r3g3d6G3dObjFv(ptr);
            *reinterpret_cast<void**>(object + 0x4A0) = 0;
        }

        void* p1C0 = *reinterpret_cast<void**>(object + 0x1C0);
        if (p1C0) {
            fn_800B8A0C(p1C0, 1);
            *reinterpret_cast<void**>(object + 0x1C0) = 0;
        }

        if (*reinterpret_cast<int*>(object + 0x5E0)) {
            *reinterpret_cast<int*>(object + 0x5E0) = 0;
        }

        void* archive = *reinterpret_cast<void**>(object + 0x5D4);
        if (archive) {
            __dt__9gfArchiveFv(archive, 1);
            *reinterpret_cast<void**>(object + 0x5D4) = 0;
        }

        h = *reinterpret_cast<void**>(object + 0x5D8);
        if (h) {
            if (h) {
                fn_1_406C(h);
                __dt__14gfFileIOHandleFv(h, -1);
                __dl__FPv(h);
            }
            *reinterpret_cast<void**>(object + 0x5D8) = 0;
        }

        if (*reinterpret_cast<int*>(object + 0x494)) {
            *reinterpret_cast<int*>(object + 0x494) = 0;
        }
        if (*reinterpret_cast<int*>(object + 0x498)) {
            *reinterpret_cast<int*>(object + 0x498) = 0;
        }
        if (*reinterpret_cast<int*>(object + 0x49C)) {
            *reinterpret_cast<int*>(object + 0x49C) = 0;
        }

        __destroy_arr(object + 0x64, fn_31_324, 0xA8, 2);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}