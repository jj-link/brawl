#include <cm/cm_camera_controller.h>
#include <gf/gf_archive.h>
#include <gr/gr_madein.h>
#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <st/st_melee.h>
#include <types.h>
#pragma force_active on

class GroundWithoutInlineSetStageData : public Ground {
public:
    virtual void setStageData(void*);
};

extern "C" {
extern char lbl_82_data_0[];
extern const float lbl_82_rodata_0[];
Ground* fn_82_4044(int, int, const char*);
Ground* fn_82_4168(int, int, const char*);
bool fn_27_2249E0(Stage*);
void fn_27_279FA4(Ground*);
void fn_82_3858(Stage*, Ground*);
void fn_82_3980(Stage*, Ground*);
void fn_82_3AD0(Stage*, Ground*);
int fn_800F6A68(gfArchive*);
float randf__Fv();
}

static u32& W(Stage* s, int o) {
    return *(u32*)((char*)s + o);
}
static float& F(Stage* s, int o) {
    return *(float*)((char*)s + o);
}
static Ground*& G(Stage* s, int o) {
    return *(Ground**)((char*)s + o);
}
static Matrix* M(Ground* g) {
    return (Matrix*)((char*)*(void**)((char*)g + 0xd4) + 0x50);
}
static void pos(Ground* g, const Vec3f& p) {
    Matrix* m = M(g);
    m->m[0][3] = p.m_x;
    m->m[1][3] = p.m_y;
    m->m[2][3] = p.m_z;
}

#define SETUP(o) \
    self->addGround(G(self, o)); \
    G(self, o)->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground); \
    ((GroundWithoutInlineSetStageData*)G(self, o))->setStageData(params)
#define INIT(o) ((grMadein*)G(self, o))->initializeEntity()
#define LOOP(o) ((grMadein*)G(self, o))->startEntityAutoLoop()
#define NODE(o, n, s) W(self, n) = G(self, o)->getNodeIndex(0, data + s)
#define MAKE(o, id, s) G(self, o) = fn_82_4044(id, (int)(data + 0xa0), data + s)
#define VIS() \
    G(self, 0x1e0)->setNodeVisibility(true, 0, W(self, 0xf78), false, false); \
    G(self, 0x1e0)->setNodeCollision(true, 0, (u16)W(self, 0xf78), false); \
    G(self, 0x1e0)->setNodeVisibility(false, 0, W(self, 0xf7c), false, false)

extern "C" void fn_82_1C8(stMelee* self) {
    char* data;
    const float* rodata;
    rodata = lbl_82_rodata_0;
    data = lbl_82_data_0;

    CameraController* camera = CameraController::getInstance();
    u8 flags = ((u8*)camera)[0x44];
    float cameraValue = rodata[2];
    ((u8*)camera)[0x44] = flags | 2;
    *(float*)((char*)camera + 0x190) = cameraValue;

    self->testStageParamInit(self->m_fileData, 10);
    self->testStageDataInit(self->m_fileData, 20, 0x8c);
    char* params = data + 4;
    W(self, 0x1d8) = (u32)params;

    MAKE(0x1dc, 0, 0xa4);
    if (G(self, 0x1dc)) {
        SETUP(0x1dc);
        INIT(0x1dc);
        LOOP(0x1dc);
        NODE(0x1dc, 0xf54, 0xb8);
    }

    MAKE(0x1e0, 1, 0xc4);
    if (G(self, 0x1e0)) {
        SETUP(0x1e0);
        INIT(0x1e0);
        LOOP(0x1e0);
        fn_27_279FA4(G(self, 0x1e0));
        M(G(self, 0x1e0))->setIdentity();
        self->createCollision(self->m_fileData, 2, G(self, 0x1e0));
        NODE(0x1e0, 0xf78, 0xdc);
        NODE(0x1e0, 0xf7c, 0xe8);
        NODE(0x1e0, 0xf80, 0xf4);
        NODE(0x1e0, 0xf84, 0x100);
        NODE(0x1e0, 0xf60, 0x10c);
        NODE(0x1e0, 0xf5c, 0x118);
        NODE(0x1e0, 0xf58, 0x124);
        NODE(0x1e0, 0xf68, 0x130);
        NODE(0x1e0, 0xf64, 0x13c);
        NODE(0x1e0, 0x1020, 0x148);
        VIS();

        MAKE(0x1e4, 9, 0x150);
        if (G(self, 0x1e4)) {
            SETUP(0x1e4);
            Vec3f start;
            Vec3f end;
            start.m_x = rodata[3];
            start.m_y = rodata[4];
            start.m_z = rodata[4];
            end.m_x = rodata[5];
            end.m_y = rodata[4];
            end.m_z = rodata[4];
            ((grMadein*)G(self, 0x1e4))->setHitPoint(
                rodata[6], &start, &end, true, 0);
            INIT(0x1e4);
            ((grMadein*)G(self, 0x1e4))->startEntity();
        }

        MAKE(0x1e8, 9, 0x150);
        if (G(self, 0x1e8)) {
            SETUP(0x1e8);
            fn_82_3AD0(self, G(self, 0x1e8));
            INIT(0x1e8);
        }
    }

    MAKE(0x1ec, 3, 0x168);
    if (G(self, 0x1ec)) {
        SETUP(0x1ec);
        INIT(0x1ec);
        G(self, 0x1ec)->setEnableCollisionStatus(false);
        fn_27_279FA4(G(self, 0x1ec));
        self->createCollision(self->m_fileData, 3, G(self, 0x1ec));
        NODE(0x1ec, 0xf3c, 0x17c);
        NODE(0x1ec, 0xf40, 0x184);
    }

    MAKE(0x1f0, 4, 0x18c);
    if (G(self, 0x1f0)) {
        SETUP(0x1f0);
        INIT(0x1f0);
        G(self, 0x1f0)->setEnableCollisionStatus(false);
        fn_27_279FA4(G(self, 0x1f0));
        self->createCollision(self->m_fileData, 4, G(self, 0x1f0));
        NODE(0x1f0, 0xf44, 0x1a0);
        W(self, 0xf48) = W(self, 0xf44);
    }

    MAKE(0x1f4, 5, 0x1ac);
    if (G(self, 0x1f4)) {
        SETUP(0x1f4);
        INIT(0x1f4);
        NODE(0x1f4, 0xf34, 0x1c8);
    }

    MAKE(0x1f8, 6, 0x1d8);
    if (G(self, 0x1f8)) {
        SETUP(0x1f8);
        INIT(0x1f8);
        NODE(0x1f8, 0xf38, 0x1f4);
    }

    W(self, 0x880) = 8;
    float zero;
    float hidden = rodata[7];
    Stage* cursor = self;
    zero = rodata[4];

    for (int i = 0; i < (int)W(self, 0x880);
         cursor = (Stage*)((char*)cursor + 0x34), ++i) {
        Ground* ground = fn_82_4044(7, (int)(data + 0xa0), data + 0x204);
        if (ground) {
            self->addGround(ground);
            ground->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
            ((GroundWithoutInlineSetStageData*)ground)->setStageData(params);
            ((grMadein*)ground)->initializeEntity();
            if (i == 0) {
                W(self, 0x884) = ground->getNodeIndex(0, data + 0x218);
                W(self, 0x888) = ground->getNodeIndex(0, data + 0x224);
            }

            Ground* other = fn_82_4168(9, (int)(data + 0xa0), data + 0x230);
            if (other) {
                self->addGround(other);
                other->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
                ((GroundWithoutInlineSetStageData*)other)->setStageData(params);
                fn_82_3858(self, other);
                ((grMadein*)other)->initializeEntity();
            }

            G(cursor, 0x200) = ground;
            G(cursor, 0x204) = other;
            if (ground) {
                Vec3f b;
                Vec3f a;
                ((grMadein*)ground)->endEntity();
                G(cursor, 0x200)->setVisibility(0);
                G(cursor, 0x200)->setEnableCollisionStatus(false);
                fn_27_279FA4(G(cursor, 0x200));
                M(G(cursor, 0x200))->setIdentity();
                a.m_x = hidden;
                a.m_y = zero;
                a.m_z = zero;
                pos(G(cursor, 0x200), a);
                ((grMadein*)G(cursor, 0x204))->endEntity();
                fn_27_279FA4(G(cursor, 0x204));
                M(G(cursor, 0x204))->setIdentity();
                b.m_x = hidden;
                b.m_y = zero;
                b.m_z = zero;
                pos(G(cursor, 0x204), b);
            }
            W(cursor, 0x210) = 0;
        }
    }

    int count = *(int*)(params + 0x34);
    int count2 = *(int*)(params + 0x30);
    if (count2 > count)
        count = count2;
    W(self, 0xf0c) = count < 32 ? count : 32;
    zero = rodata[7];
    hidden = rodata[4];
    cursor = self;

    for (int k = 0; k < (int)W(self, 0xf0c);
         cursor = (Stage*)((char*)cursor + 0x34), ++k) {
        Ground* ground = fn_82_4044(8, (int)(data + 0xa0), data + 0x248);
        if (ground) {
            self->addGround(ground);
            ground->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
            ((GroundWithoutInlineSetStageData*)ground)->setStageData(params);
            ((grMadein*)ground)->initializeEntity();
            if (k == 0) {
                W(self, 0xf10) = ground->getNodeIndex(0, data + 0x25c);
                W(self, 0xf14) = ground->getNodeIndex(0, data + 0x268);
            }

            Ground* other = fn_82_4168(9, (int)(data + 0xa0), data + 0x230);
            if (other) {
                self->addGround(other);
                other->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
                ((GroundWithoutInlineSetStageData*)other)->setStageData(params);
                fn_82_3980(self, other);
                ((grMadein*)other)->initializeEntity();
            }

            G(cursor, 0x88c) = ground;
            G(cursor, 0x890) = other;
            if (ground) {
                Vec3f b;
                Vec3f a;
                ((grMadein*)ground)->endEntity();
                G(cursor, 0x88c)->setVisibility(0);
                G(cursor, 0x88c)->setEnableCollisionStatus(false);
                fn_27_279FA4(G(cursor, 0x88c));
                M(G(cursor, 0x88c))->setIdentity();
                a.m_x = zero;
                a.m_y = hidden;
                a.m_z = hidden;
                pos(G(cursor, 0x88c), a);
                ((grMadein*)G(cursor, 0x890))->endEntity();
                fn_27_279FA4(G(cursor, 0x890));
                M(G(cursor, 0x890))->setIdentity();
                b.m_x = zero;
                b.m_y = hidden;
                b.m_z = hidden;
                pos(G(cursor, 0x890), b);
            }
            W(cursor, 0x89c) = 0;
        }
    }

    if (fn_27_2249E0(self)) {
        MAKE(0x1fc, 10, 0x274);
        if (G(self, 0x1fc)) {
            SETUP(0x1fc);
            INIT(0x1fc);
            LOOP(0x1fc);
            fn_27_279FA4(G(self, 0x1fc));
            M(G(self, 0x1fc))->setIdentity();
            NODE(0x1fc, 0xff8, 0x288);
            NODE(0x1fc, 0xffc, 0x29c);
            NODE(0x1fc, 0x1000, 0x2b0);
            NODE(0x1fc, 0x1004, 0x2c4);
        }
    } else {
        G(self, 0x1fc) = 0;
    }

    self->initCameraParam();
    void* positionData = self->m_fileData->getData(Data_Type_Model, 100, 0xfffe);
    if (positionData) {
        nw4r::g3d::ResFile positions(positionData);
        self->createStagePositions(&positions);
    } else {
        self->createStagePositions();
    }

    self->createWind2ndOnly();
    self->registScnAnim(
        (nw4r::g3d::ResFileData*)self->m_fileData->getData(Data_Type_Scene, 0, 0xfffe),
        0);
    F(self, 0xf90) = *(float*)((char*)G(self, 0x1d8) + 0x38);
    VIS();

    W(self, 0xf88) = 0;
    W(self, 0xf8c) = 0;
    float random = rodata[8] * randf__Fv();
    float* bounds = (float*)G(self, 0x1d8);
    float range = bounds[7] - bounds[6];
    float result = bounds[6] + range * random;
    W(self, 0xf1c) = 0;
    W(self, 0xf20) = 0;
    F(self, 0xf94) = result;

    float range2;
    float random2 = rodata[8] * randf__Fv();
    bounds = (float*)G(self, 0x1d8);
    range2 = bounds[16] - bounds[15];
    float value = bounds[15] + range2 * random2;
    *(u8*)((char*)self + 0xf6c) = 0;
    F(self, 0xf4c) = rodata[4];
    *(u8*)((char*)self + 0xf6d) = 0;
    W(self, 0xf70) = 0;
    W(self, 0xf74) = 0;
    F(self, 0xf18) = value;

    W(self, 0xfac) = *(u32*)data;
    W(self, 0xfb0) = 0;
    F(self, 0xfb4) = rodata[4];
    F(self, 0xfb8) = rodata[4];
    F(self, 0xfbc) = rodata[4];
    F(self, 0xfc0) = rodata[4];
    F(self, 0xfc4) = rodata[4];
    F(self, 0xfc8) = rodata[4];
    F(self, 0xfcc) = rodata[4];
    F(self, 0xfd0) = rodata[4];
    F(self, 0xfd4) = rodata[4];
    F(self, 0xfd8) = rodata[4];
    W(self, 0x1024) = 0;
    F(self, 0xfdc) = rodata[4];
    F(self, 0xfe0) = rodata[4];
    F(self, 0xfe4) = rodata[4];
    F(self, 0xfe8) = rodata[4];
    F(self, 0xfec) = rodata[4];
    F(self, 0xff0) = rodata[4];
    F(self, 0xff4) = rodata[9];
    W(self, 0x103c) = 0;

    self->initPosPokeTrainer(4, 1);
    self->loadStageAttrParam(self->m_fileData, 30);
    W(self, 0x1040) = fn_800F6A68(self->m_fileData);
}
