#pragma force_active on

#include <revolution/GX/GXGeometry.h>

extern "C" {
void fn_80162384(float*, float*, float);
void fn_8017C48C(void*, void*, int);
void fn_8017C748(void*, void*, int);
void fn_8017CA88(void*, void*, int);

extern const float lbl_805A303C;
extern const float lbl_805A304C;
extern const float lbl_805A3060;
extern const float lbl_805A3064;
}

struct Pair {
    float x;
    float y;

    void set(float a, float b) {
        y = b;
        x = a;
    }
};

inline void setCirclePoint(Pair* p, int i, float step) {
    float fi = (float)i;
    fn_80162384(&p->x, &p->y, lbl_805A3064 * (step * fi));
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

extern "C" void fn_8017CE40(void* a0, Node* a1, int a2) {
    Inner* in = a1->obj->inner;
    int n = in->count;

    if (n >= 3) {
        Pair* p;
        Pair* arr = (Pair*)__alloca((n + 1) * 8);

        if (arr) {
            float fn_ = (float)n;
            float f29 = lbl_805A3060 / fn_;
            arr[0].y = lbl_805A303C;
            p = arr + 1;
            int i;

            arr[0].x = lbl_805A304C;

            for (i = 1; i < n; p++, i++) {
                setCirclePoint(p, i, f29);
            }

            arr[n].set(lbl_805A304C, lbl_805A303C);
            a1->arr = arr;

            switch (in->mode & 7) {
            case 0:
            default:
                GXSetCullMode(GX_CULL_FRONT);
                fn_8017C48C(a0, a1, a2);
                GXSetCullMode(GX_CULL_BACK);
                fn_8017C48C(a0, a1, a2);
                break;

            case 1:
                GXSetCullMode(GX_CULL_FRONT);
                fn_8017C748(a0, a1, a2);
                GXSetCullMode(GX_CULL_BACK);
                fn_8017C748(a0, a1, a2);
                break;

            case 2:
                GXSetCullMode(GX_CULL_FRONT);
                fn_8017CA88(a0, a1, a2);
                GXSetCullMode(GX_CULL_BACK);
                fn_8017CA88(a0, a1, a2);
                break;
            }
        }
    }
}
