#pragma force_active on
struct Vec2f { float x; float y; };
struct Vec3f { float x; float y; float z; };

struct aiMgr {
    int setDangerZone(Vec2f* a, Vec2f* b, int danger, bool x, bool y);
};
extern aiMgr* g_aiMgr;
extern "C" void fn_27_1F299C(aiMgr*, int);
extern float lbl_54_rodata_19C;
extern float lbl_54_rodata_1A0;

struct NodeData {
    float x0;
    float pad4[2];
    float x3;
    float x4;
};

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void getNodePosition(Vec3f* out, unsigned long a, unsigned long b);
    char p1[0x158 - 0x40];
    unsigned char* f158;
    char p2[0x184 - 0x15c];
    NodeData* f184;
    char p3[0x1a8 - 0x188];
    int f1a8;
    int f1ac;
    char p4[0x1d8 - 0x1b0];
    int f1d8;
};

struct Pair {
    Vec2f a;
    float gap;
    Vec2f b;
};

extern "C" void fn_54_F354(Ground* self) {
    if (*self->f158 == 4) {
        if (self->f1d8 != -1) {
            fn_27_1F299C(g_aiMgr, self->f1d8);
            self->f1d8 = -1;
        }
    } else {
        Vec3f p1;
        Vec3f p2;
        Pair tmp;
        self->getNodePosition(&p1, 0, self->f1a8);
        self->getNodePosition(&p2, 0, self->f1ac);
        NodeData* d = self->f184;
        tmp.a.x = d->x0;
        tmp.a.y = lbl_54_rodata_19C + lbl_54_rodata_1A0 * (p1.y + p2.y);
        tmp.b.x = d->x3;
        tmp.b.y = d->x4;
        if (tmp.a.y > lbl_54_rodata_19C) {
            tmp.a.y = lbl_54_rodata_19C;
        }
        if (tmp.a.y < tmp.b.y) {
            tmp.a.y = tmp.b.y;
        }
        Vec2f a;
        Vec2f b;
        b.x = tmp.b.x;
        b.y = tmp.b.y;
        a.x = tmp.a.x;
        a.y = tmp.a.y;
        self->f1d8 = g_aiMgr->setDangerZone(&a, &b, self->f1d8, false, false);
    }
}
