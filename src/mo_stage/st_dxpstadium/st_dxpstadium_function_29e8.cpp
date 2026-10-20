#pragma force_active on
struct Vec2 {
    float x, y;

    Vec2() {}

    Vec2& operator=(const Vec2& b) {
        __memcpy(this, &b, sizeof(Vec2));
        return *this;
    }

    friend Vec2 operator+(const Vec2& a, const Vec2& b) {
        Vec2 r;
        r.x = a.x + b.x;
        r.y = a.y + b.y;
        return r;
    }

    friend Vec2 operator*(const Vec2& a, float b) {
        Vec2 r;
        r.x = a.x * b;
        r.y = a.y * b;
        return r;
    }
};

struct Stage {
    char pad[0x615];
    unsigned char enabled;
    char pad2[0x6e8 - 0x616];
    Vec2 a, b;
};

struct Tex {
    unsigned long v[8];
};

struct Srt {
    unsigned long flags;
    unsigned long mode;
    float sx, sy, rot, tx, ty;
};

extern "C" {
extern const float lbl_83_rodata_14;
extern char lbl_83_data_B4[];

void* getGround__5StageFi(Stage*, int);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
Tex* GetTexObj__Q34nw4r3g3d9ResTexObjF11_GXTexMapID(void*, int);
void* getInstance__12gfCopyEFBMgrFv();
bool isValid__12gfCopyEFBMgrFi(void*, int);
Tex* getCopyEFBTex__12gfCopyEFBMgrFi(void*, int);
void SetMapMode__Q34nw4r3g3d9ResTexSrtFUlUlii(
    void*, unsigned long, unsigned long, int, int);
void fn_83_25BC(Stage*);

void fn_83_29E8(Stage* self) {
    if (self->enabled) {
        Vec2 center;
        center = (self->a + self->b) * lbl_83_rodata_14;
        float width = self->b.x - self->a.x;
        float height = self->b.y - self->a.y;

        void* ground = getGround__5StageFi(self, 0);
        void* obj = **(void***)((char*)ground + 0x44);
        void* mdl = *(void**)((char*)obj + 0xe8);
        void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc(
            &mdl, lbl_83_data_B4);

        Srt* srt;
        void* texRes = (char*)mat + 0x3c;
        Tex* tex = GetTexObj__Q34nw4r3g3d9ResTexObjF11_GXTexMapID(
            &texRes, 0);

        if (isValid__12gfCopyEFBMgrFi(
                getInstance__12gfCopyEFBMgrFv(), 0) == true) {
            *tex = *getCopyEFBTex__12gfCopyEFBMgrFi(
                getInstance__12gfCopyEFBMgrFv(), 0);
        }

        srt = (Srt*)((char*)mat + 0x1a4);
        SetMapMode__Q34nw4r3g3d9ResTexSrtFUlUlii(
            &srt, 0, 0, -1, -1);

        Srt* values = srt;
        values->sx = width;
        values->sy = height;
        float half = lbl_83_rodata_14;
        float x = center.x - half * width;
        float y = center.y - half * height;
        values->tx = -x / width;
        values->ty = -y / height;

        srt->flags = (srt->flags & ~15UL) | 5;
        fn_83_25BC(self);
    }
}
}
