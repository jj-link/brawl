#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];
public:
    virtual void fn(int arg);
};

extern "C" {
extern void* g_gfSceneRoot;

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8000D7B8(void*);
void __dl__FPv(void*);

void* fn_8010B9E4(u8* object, int deleting) {
    if (object) {
        u8* cursor = object;
        for (int i = 0; i < 7; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x154);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = object;
        for (int i = 0; i < 0x55; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor);
            if (entry) {
                entry->fn(1);
            }
        }

        fn_8000D7B8(g_gfSceneRoot);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}