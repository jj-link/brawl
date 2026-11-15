#pragma force_active on

#include <revolution/GX/GXGeometry.h>

extern "C" {
void fn_80162384(float*, float*, float);
void fn_801805C8(void*, void*, int, int);
void fn_801808C0(void*, void*, int, int);
void fn_80180C74(void*, void*, int, int);

extern const float lbl_805A3074;
extern const float lbl_805A3078;
extern const float lbl_805A30A4;
extern const float lbl_805A30A8;
extern const double lbl_805A3098;
}

struct Pair {
    float x;
    float y;
};

inline void setCirclePoint(Pair* p, int i, float step, float k) {
    float fi = (float)i;
    fn_80162384(&p->y, &p->x, k * (step * fi));
}

struct Inner {
    unsigned char pad[0x140];
    unsigned char count;
    unsigned char pad2;
    unsigned char mode;
};

struct Obj {
    unsigned char pad[0x24];
    Inner* inner;
};

struct Node {
    Obj* obj;
    unsigned char pad[0xd0];
    Pair* arr;
};

extern "C" void fn_801811DC(void* a0, Node* a1, int a2, int a3) {
    Inner* in = a1->obj->inner;
    int n = in->count;

    if (n >= 3) {
        Pair* p;
        Pair* arr = (Pair*)__alloca((n + 1) * 8);

        if (arr) {
            float fn_ = (float)n;
            float f29 = lbl_805A30A4 / fn_;
            arr[0].x = lbl_805A3078;
            arr[0].y = lbl_805A3074;
            p = arr + 1;
            int i;

            for (i = 1; i < n; p++, i++) {
                setCirclePoint(p, i, f29, lbl_805A30A8);
            }

            arr[n].x = lbl_805A3078;
            arr[n].y = lbl_805A3074;
            a1->arr = arr;

            switch (in->mode & 7) {
            case 0:
            default:
                GXSetCullMode(GX_CULL_FRONT);
                fn_801805C8(a0, a1, a2, a3);
                GXSetCullMode(GX_CULL_BACK);
                fn_801805C8(a0, a1, a2, a3);
                break;

            case 1:
                GXSetCullMode(GX_CULL_FRONT);
                fn_801808C0(a0, a1, a2, a3);
                GXSetCullMode(GX_CULL_BACK);
                fn_801808C0(a0, a1, a2, a3);
                break;

            case 2:
                GXSetCullMode(GX_CULL_FRONT);
                fn_80180C74(a0, a1, a2, a3);
                GXSetCullMode(GX_CULL_BACK);
                fn_80180C74(a0, a1, a2, a3);
                break;
            }
        }
    }
}