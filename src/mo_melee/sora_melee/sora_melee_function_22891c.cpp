#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_27_data_4A770[];
extern void* g_gfSceneRoot;
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8000D1B8(void*, int, void*);
}

extern "C" void* fn_27_22891C(u8* self, int deleting)
{
    if (self) {
        *(void**)(self + 0x3C) = lbl_27_data_4A770;
        int p80 = *(int*)(self + 0x80);
        if (p80) {
            if (p80) {
                __dla__FPv((void*)(p80 - 0x10));
            }
        }

        for (unsigned int i = 0; i < *(unsigned short*)(self + 0x44); i++) {
            void* ptr = *(void**)(*(char**)(self + 0x48) + i * 0x10 + 0xC);
            if (ptr) {
                __dla__FPv(ptr);
            }
        }

        void* arr = *(void**)(self + 0x48);
        if (arr) {
            __dla__FPv(arr);
        }

        *(int*)((char*)g_gfSceneRoot + 0x474) = 0;
        *(int*)((char*)g_gfSceneRoot + 0x478) = 0;

        fn_8000D1B8(g_gfSceneRoot, 0, *(void**)(self + 0x74));
        Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(self + 0x74));
        *(void**)(self + 0x74) = 0;

        fn_8000D1B8(g_gfSceneRoot, 0, *(void**)(self + 0x78));
        Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(self + 0x78));
        *(void**)(self + 0x78) = 0;

        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}