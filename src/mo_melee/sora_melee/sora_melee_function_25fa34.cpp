#pragma force_active on
extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
void __dla__FPv(void*);
extern void* g_gfSceneRoot;

struct Ground {
    char pad0[0x44];
    void* arr44;
    void* arr48;
    char pad4C[0xC];
    unsigned int count58;
};

void unloadData__6GroundFv(Ground* self) {
    if (self->arr44 != 0) {
        unsigned int offset;
        unsigned int count = self->count58;
        unsigned int i;
        void* null = 0;
        i = 0;
        offset = 0;
        while (i != count) {
            *(void**)((char*)*(void**)((char*)self->arr44 + offset) + 0x11C) = null;
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, *(void**)((char*)self->arr44 + offset));
            Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)((char*)self->arr44 + offset));
            *(void**)((char*)self->arr44 + offset) = null;
            i++;
            offset += 4;
        }
        __dla__FPv(self->arr44);
        self->arr44 = 0;
    }
    if (self->arr48 != 0) {
        unsigned int count = self->count58;
        unsigned int i = 0;
        unsigned int offset = 0;
        void* null = 0;
        while (i != count) {
            void* elem = *(void**)((char*)self->arr48 + offset);
            void* f0C = *(void**)((char*)elem + 0xC);
            if (f0C) Destroy__Q34nw4r3g3d6G3dObjFv(f0C);
            void* f08 = *(void**)((char*)elem + 0x8);
            if (f08) Destroy__Q34nw4r3g3d6G3dObjFv(f08);
            void* f10 = *(void**)((char*)elem + 0x10);
            if (f10) Destroy__Q34nw4r3g3d6G3dObjFv(f10);
            void* f14 = *(void**)((char*)elem + 0x14);
            if (f14) Destroy__Q34nw4r3g3d6G3dObjFv(f14);
            void* f18 = *(void**)((char*)elem + 0x18);
            if (f18) Destroy__Q34nw4r3g3d6G3dObjFv(f18);
            void* f1C = *(void**)((char*)elem + 0x1C);
            if (f1C) Destroy__Q34nw4r3g3d6G3dObjFv(f1C);
            void* f00 = *(void**)((char*)elem + 0x0);
            if (f00 && *(unsigned char*)((char*)elem + 0x4)) {
                free__13gfHeapManagerFPv(f00);
                *(void**)((char*)elem + 0x0) = null;
            }
            *(void**)((char*)elem + 0xC) = null;
            *(void**)((char*)elem + 0x8) = null;
            *(void**)((char*)elem + 0x10) = null;
            *(void**)((char*)elem + 0x14) = null;
            *(void**)((char*)elem + 0x18) = null;
            *(void**)((char*)elem + 0x1C) = null;
            free__13gfHeapManagerFPv(*(void**)((char*)self->arr48 + offset));
            *(void**)((char*)self->arr48 + offset) = null;
            i++;
            offset += 4;
        }
        __dla__FPv(self->arr48);
        self->arr48 = 0;
    }
}
}
