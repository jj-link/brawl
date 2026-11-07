#include <types.h>
#pragma force_active on

struct Mtx34 {
    unsigned int w[12];
};

class Class_8042EC38;

struct Class_8042EC38_base {
    Class_8042EC38* next;
    char pad0[0x0D - 0x04];
    unsigned char flags;
    char pad1[0x48 - 0x0E];
};

class Class_8042EC38 : public Class_8042EC38_base {
public:
    virtual void fn_8005C798();
    virtual void fn_8005CAA0();
    virtual void fn_8005CA18();
    virtual void fn_8005A898();
    virtual void fn_8005CE70();
};

struct CamData {
    char pad0[0xA8];
    int flags;
    float ac;
    float b0;
    float b4;
    char pad1[4];
    float bc;
    float c0;
    float c4;
    float c8;
};

struct Self {
    char pad0[0x84];
    Mtx34 m84;
    Mtx34 mB4;
    char pad1[0xF0 - 0xE4];
    unsigned int unkF0;
    char pad2[0x138 - 0xF4];
    unsigned int unk138;
};

struct Sub {
    char pad0[0x108];
    unsigned int unk108;
};

extern "C" {
void GXSetFog(int, unsigned char*, float, float, float, float);
void gfDrawResetLight__Fv();
void* fn_801AC554(void*, int);
void fn_801A7DBC(void**, void*);
void fn_801A8048(void**);
void fn_801A80CC(void**);
void fn_801A8194(void**);
void fn_801ECBF0(void*, float, float, float, float, float, float);
void fn_801ECCE8(void*, float, float, float, float, float, float, float, float);
void fn_801F51DC(void*, int);
void fn_801F5258(void*, int);
void* fn_801647B4();
void fn_8005F668(void*);
void setIdentity__6MatrixFv(void*);
}

extern float lbl_805A18EC;
extern float lbl_805A1900;
extern float lbl_805A1904;
extern float lbl_805A1908;
extern void* g_gfSceneRoot;
extern void* g_ecMgr;

extern "C" void fn_8005B838(Self* self, int arg1) {
    Mtx34 spA0;
    Mtx34 sp70;
    Mtx34 sp40;
    Mtx34 sp10;
    void* spC;
    unsigned int sp8;
    Sub* p;
    int mode;
    void* root;
    void* r3;
    CamData* cam;
    Class_8042EC38* node;
    Class_8042EC38* sentinel;
    unsigned int flag27;
    int var0;
    unsigned char* mgr;

    sp8 = 0;
    GXSetFog(0, (unsigned char*)&sp8, lbl_805A18EC, lbl_805A1900, lbl_805A18EC, lbl_805A1900);
    p = (Sub*)((char*)self + arg1 * 12);
    if (p->unk108 != 0) {
        gfDrawResetLight__Fv();
        mode = 0;
        if (arg1 > 1) {
            mode = 1;
        }
        root = g_gfSceneRoot;
        if (mode == 0) {
            r3 = *(void**)((char*)root + 0x40);
        } else if (mode == 1) {
            r3 = *(void**)((char*)root + 0x44);
        } else {
            r3 = 0;
        }
        spC = fn_801AC554(r3, 0);
        fn_801A7DBC(&spC, &spA0);
        self->m84 = spA0;
        cam = (CamData*)spC;
        if (cam->flags == 0) {
            fn_801ECBF0(&sp40, cam->ac, cam->b0, lbl_805A1904, lbl_805A1908, lbl_805A1904, lbl_805A1904);
            self->mB4 = sp40;
        } else {
            float c8 = cam->c8;
            float c4 = cam->c4;
            float c0 = cam->c0;
            float bc = cam->bc;
            fn_801ECCE8(&sp10, bc, c0, c4, c8, lbl_805A1904, lbl_805A1908, lbl_805A1904, lbl_805A1904);
            self->mB4 = sp10;
        }
        setIdentity__6MatrixFv(&sp70);
        fn_801F51DC(&sp70, 0);
        fn_801F5258(&sp70, 0);
        self->unkF0 = 0;
        fn_801A8194(&spC);
        fn_801A8048(&spC);
        fn_801A80CC(&spC);
        flag27 = 0;
        var0 = 0;
        if (mode == 0) {
            var0 = self->unk138;
        }
        if (var0 != 0) {
            mgr = (unsigned char*)fn_801647B4();
            mgr[0x5064] = 1;
            flag27 = 1;
        }
        sentinel = (Class_8042EC38*)((char*)p + 0x10C);
        for (node = sentinel->next; node != sentinel; node = node->next) {
            if ((node->flags >> 6) & 1) {
                node->fn_8005CE70();
            }
        }
        if (flag27 == 1) {
            mgr = (unsigned char*)fn_801647B4();
            mgr[0x5064] = 0;
        }
    } else if (arg1 == 1 && self->unk138 != 0) {
        self->unk138 = 0;
    }
    if (arg1 == 1) {
        fn_8005F668(g_ecMgr);
    }
}
