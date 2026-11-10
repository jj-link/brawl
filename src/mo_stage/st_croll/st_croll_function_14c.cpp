#pragma force_active on
extern "C" {

void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_803F0D4C(void* block, void (*destroy)(void*, int));
void fn_8005E3C8(void*, const unsigned char*, float);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
extern void* g_efScreen;
extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_4;
extern char lbl_90_data_2AD0[];
void fn_90_2F8(void*, int);
void fn_90_338(char*, int);

}

typedef unsigned char u8;
typedef unsigned int u32;

struct StageObj {
    u8 pad0[4];
    u32 flags;
    u8 padding[0x6AF4 - 8];
    u8 effect;
};

struct stMelee {
    u8 pad0[0x3c];
    void* f3C;
    u8 pad40[0x1e0 - 0x40];
    void* f1E0;
    void* f1E4;
    u8 pad1E8[0x14];
    u8 f1FC;
    u8 pad1FD[7];
    u32 f204;
    u8 pad208[4];
    void* f20C;
    void* f210;
    void* f214;
    void* f218;
    void* f21C;
};

extern "C" void* fn_90_14C(void* self, int deleting) {
    u8 spC[4];
    u8 sp8;
    if (self) {
        stMelee* s = (stMelee*)self;
        void* block = s->f218;
        s->f3C = (void*)lbl_90_data_2AD0;
        if (block) {
            if (block)
                __dla__FPv((char*)block - 0x10);
            s->f218 = 0;
        }
        if (s->f210) {
            fn_803F0D4C(s->f210, (void (*)(void*, int))fn_90_2F8);
            s->f210 = 0;
        }
        if (s->f214) {
            fn_803F0D4C(s->f214, (void (*)(void*, int))fn_90_338);
            s->f214 = 0;
        }
        void* p20C = s->f20C;
        if (p20C) {
            __dl__FPv(p20C);
            s->f20C = 0;
        }
        void* p21C = s->f21C;
        if (p21C) {
            if (p21C) {
                StageObj* so = (StageObj*)p21C;
                if (so->flags & 2) {
                    spC[0] = so->effect;
                    fn_8005E3C8(g_efScreen, &spC[0], lbl_90_rodata_0);
                    so->flags &= ~2;
                }
                __dl__FPv(p21C);
            }
            s->f21C = 0;
        }
        if (s->f1E4) {
            Destroy__Q34nw4r3g3d6G3dObjFv(s->f1E4);
            s->f1E4 = 0;
        }
        if (s->f1E0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(s->f1E0);
            s->f1E0 = 0;
        }
        releaseArchive__15stCommonGimmickFv(self);
        if (s->f204) {
            s->f204 = 0;
            sp8 = s->f1FC;
            fn_8005E3C8(g_efScreen, &sp8, lbl_90_rodata_4);
        }
        __dt__7stMeleeFv(self, 0);
        if (deleting > 0)
            __dl__FPv(self);
    }
    return self;
}
