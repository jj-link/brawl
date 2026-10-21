#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];

public:
    virtual ~MenuObject();
};

extern "C" {
extern u8 lbl_2_data_B00[];
extern void* g_gfSceneRoot;

void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_2_61FC(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_2_data_B00;
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(
            g_gfSceneRoot, *reinterpret_cast<void**>(object + 0x1C4));

        u8* cursor = object;
        for (unsigned int i = 0; i < 15; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x1C4);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
                *reinterpret_cast<void**>(cursor + 0x1C4) = 0;
            }
        }

        cursor = object;
        for (unsigned int i = 0; i < 31; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0x148);
            if (entry) {
                delete entry;
                *reinterpret_cast<void**>(cursor + 0x148) = 0;
            }
        }

        fn_800B8A0C(*reinterpret_cast<void**>(object + 0x204), 1);
        exit__6gfTaskFv(*reinterpret_cast<void**>(object + 0x200));
        *reinterpret_cast<void**>(object + 0x200) = 0;
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0)
            __dl__FPv(object);
    }

    return object;
}
}
