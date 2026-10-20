#include <string.h>
#pragma force_active on

struct Vec2f {
    float x, y;

    static void copy(Vec2f& dst, const Vec2f& src) {
        __memcpy(&dst, &src, sizeof(Vec2f));
    }

    Vec2f() {}
    Vec2f(float a, float b) : x(a), y(b) {}

    friend Vec2f operator+(const Vec2f& a, const Vec2f& b) {
        Vec2f r;
        r.x = a.x + b.x;
        r.y = a.y + b.y;
        return r;
    }

    friend Vec2f operator*(const Vec2f& a, float b) {
        Vec2f r;
        r.x = a.x * b;
        r.y = a.y * b;
        return r;
    }
};

struct Stage {
    char pad[0x6ac];
    int state;
    char pad2[0x104];
    Vec2f low, high;
};

struct TexObj {
    unsigned int words[8];
};

struct TexSrt {
    unsigned int flags;
    unsigned int pad;
    float sx, sy, rot, tx, ty;
};

extern "C" {
extern const float lbl_59_rodata_54;
extern char lbl_59_data_2D8[];

void* getGround__5StageFi(Stage*, int);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
TexObj* GetTexObj__Q34nw4r3g3d9ResTexObjF11_GXTexMapID(void*, int);
void* getInstance__12gfCopyEFBMgrFv();
bool isValid__12gfCopyEFBMgrFi(void*, int);
TexObj* getCopyEFBTex__12gfCopyEFBMgrFi(void*, int);
void SetMapMode__Q34nw4r3g3d9ResTexSrtFUlUlii(
    void*, unsigned long, unsigned long, int, int);
void fn_59_2E24(Stage*);

void fn_59_3250(Stage* self) {
    if (self->state != 0) {
        Vec2f center;
        Vec2f::copy(center, (self->low + self->high) * lbl_59_rodata_54);
        float width = self->high.x - self->low.x;
        float height = self->high.y - self->low.y;

        void* ground = getGround__5StageFi(self, 0);
        void* obj = **(void***)((char*)ground + 0x44);
        void* mdl = *(void**)((char*)obj + 0xe8);
        char* mat = (char*)GetResMat__Q34nw4r3g3d6ResMdlCFPCc(
            &mdl, lbl_59_data_2D8);

        TexSrt* srt;
        void* tex = mat + 0x3c;
        TexObj* texobj =
            GetTexObj__Q34nw4r3g3d9ResTexObjF11_GXTexMapID(&tex, 0);

        if (isValid__12gfCopyEFBMgrFi(
                getInstance__12gfCopyEFBMgrFv(), 0) == true) {
            *texobj = *getCopyEFBTex__12gfCopyEFBMgrFi(
                getInstance__12gfCopyEFBMgrFv(), 0);
        }

        srt = (TexSrt*)(mat + 0x1a4);
        SetMapMode__Q34nw4r3g3d9ResTexSrtFUlUlii(
            &srt, 0, 0, -1, -1);

        float half = lbl_59_rodata_54;
        TexSrt* values = srt;
        values->sx = width;
        values->sy = height;
        values->tx = -(center.x - half * width) / width;
        values->ty = -(center.y - half * height) / height;
        srt->flags = (srt->flags & ~0xf) | 5;

        fn_59_2E24(self);
    }
}
}
