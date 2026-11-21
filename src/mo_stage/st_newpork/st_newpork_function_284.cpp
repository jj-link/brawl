#include <st/stage.h>
#include <gr/gr_madein.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_joint.h>
#include <mt/mt_matrix.h>
#pragma force_active on

extern "C" {
extern char lbl_69_data_0[];
extern const float lbl_69_rodata_0[];
grMadein* fn_69_2724(int, const char*, const char*);
void fn_69_2C70(grMadein*);
void fn_69_2E3C(grMadein*);
void fn_69_2848(grMadein*, Vec3f*, unsigned long, bool, float);
void fn_27_279FA4(grMadein*);
void fn_27_279FC8(grMadein*, Matrix*, bool);
grMadein* fn_27_27BDB8(int, const char*);
void fn_27_27BF44(grMadein*, int, int, int, int);
grCollisionJoint* getJoint__11grCollisionFUs(grCollision*, unsigned int);
}

class NewporkGround : public grMadein {
public:
    virtual void setStageData(void*);
};

struct TargetGroundBase { char pad[0x3c]; };

class TargetGround : public TargetGroundBase {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void setTarget(void*);
};

class NewporkStage : public Stage {
public:
    gfArchive* archive;
    char pad1a4[0x34];
    NewporkGround* g1d8;
    NewporkGround* g1dc;
    NewporkGround* g1e0;
    NewporkGround* g1e4;
    NewporkGround* g1e8;
    NewporkGround* g1ec;
    char pad1f0[4];
    NewporkGround* g1f4;
    NewporkGround* g1f8;
    NewporkGround* g1fc;
    NewporkGround* g200;
    NewporkGround* g204;
    void* param;
    unsigned long node20c;
    unsigned long node210;
    unsigned long node214;
    unsigned long node218;
    unsigned long node21c;
    unsigned long node220;
    int value224;
    int value228;
    char pad22c[0x10];
    int value23c;
    int value240;
    char pad244[0x0c];
    int value250;
    int value254;
    char pad258[0xf4];
    grCollisionJoint* joint34c;
};

extern "C" void fn_69_284(Stage* stage)
{
    NewporkStage* self = static_cast<NewporkStage*>(stage);
    const float* rodata = lbl_69_rodata_0;
    char* base = lbl_69_data_0;
    self->testStageParamInit(self->archive, 10);
    self->param = base + 4;

    self->g1d8 = (NewporkGround*)fn_69_2724(0, base + 0x5c, base + 0x60);
    if (self->g1d8) {
        self->addGround(self->g1d8);
        self->g1d8->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1d8->setStageData(self->m_stageData);
        self->g1d8->startEntityAutoLoop();
        self->node20c = self->g1d8->getNodeIndex(0, base + 0x70);
        self->node210 = self->g1d8->getNodeIndex(0, base + 0x88);
    }

    self->g1dc = (NewporkGround*)fn_69_2724(8, base + 0x5c, base + 0x98);
    if (self->g1dc) {
        self->addGround(self->g1dc);
        self->g1dc->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1dc->setStageData(self->m_stageData);
        self->g1dc->startEntityAutoLoop();
    }

    self->g1e0 = (NewporkGround*)fn_69_2724(1, base + 0x5c, base + 0xb0);
    if (self->g1e0) {
        self->addGround(self->g1e0);
        self->g1e0->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1e0->setStageData(self->m_stageData);
        self->g1e0->startEntityAutoLoop();
        fn_27_279FA4(self->g1e0);
    }

    self->g1e4 = (NewporkGround*)fn_69_2724(2, base + 0x5c, base + 0xc0);
    if (self->g1e4) {
        self->addGround(self->g1e4);
        self->g1e4->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1e4->setStageData(self->m_stageData);
        self->node214 = self->g1d8->getNodeIndex(0, base + 0xd4);
        fn_69_2C70(self->g1e4);
        const float zero = rodata[0];
        Vec3f start;
        start.m_x = rodata[1];
        start.m_y = zero;
        start.m_z = zero;
        Vec3f end;
        end.m_x = rodata[2];
        end.m_y = zero;
        end.m_z = zero;
        self->g1e4->setHitPoint(rodata[3], &start, &end, true, 0);
        *((unsigned char*)self->g1e4 + 0x16c) |= 4;
        self->g1e4->initializeEntity();
        self->g1e4->startEntity();
        self->g1e4->setMotionRatio(rodata[0]);
        fn_27_279FA4(self->g1e4);
    }

    self->g1e8 = (NewporkGround*)fn_69_2724(3, base + 0x5c, base + 0xec);
    if (self->g1e8) {
        self->addGround(self->g1e8);
        self->g1e8->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1e8->setStageData(self->m_stageData);
        fn_69_2E3C(self->g1e8);
        self->g1e8->initializeEntity();
        self->g1e8->setEnableCollisionStatus(false);
        fn_27_279FA4(self->g1e8);
    }

    self->g1ec = (NewporkGround*)fn_69_2724(7, base + 0x5c, base + 0x100);
    if (self->g1ec) {
        self->addGround(self->g1ec);
        self->g1ec->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1ec->setStageData(self->m_stageData);
        fn_69_2E3C(self->g1ec);
        self->g1ec->initializeEntity();
        self->g1ec->setEnableCollisionStatus(false);
        fn_27_279FA4(self->g1ec);
    }

    self->g1f4 = (NewporkGround*)fn_69_2724(5, base + 0x5c, base + 0x118);
    if (self->g1f4) {
        self->addGround(self->g1f4);
        self->g1f4->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g1f4->setStageData(self->m_stageData);
        self->g1f4->initializeEntity();
        self->node218 = self->g1f4->getNodeIndex(0, base + 0x130);
    }

    self->g1f8 = (NewporkGround*)fn_69_2724(6, base + 0x5c, base + 0x144);
    if (self->g1f8) {
        self->addGround(self->g1f8);
        self->g1f8->startup(self->archive, 0, (gfSceneRoot::LayerType)1);
        self->g1f8->setStageData(self->m_stageData);
        self->node21c = self->g1f8->getNodeIndex(0, base + 0x164);
        self->node220 = self->g1f8->getNodeIndex(0, base + 0x188);
        Vec3f pos;
        pos.m_x = rodata[0];
        pos.m_y = rodata[3];
        pos.m_z = rodata[4];
        fn_69_2848(self->g1f8, &pos, self->node220, true, rodata[5]);
        self->g1f8->initializeEntity();
        fn_27_279FA4(self->g1f8);
        Matrix matrix;
        fn_27_279FC8(self->g1f8, &matrix, true);

        self->g1fc = (NewporkGround*)fn_69_2724(4, base + 0x5c, base + 0x5c);
        if (self->g1fc) {
            self->addGround(self->g1fc);
            self->g1fc->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
            self->g1fc->setStageData(self->m_stageData);
            Vec3f pos2;
            pos2.m_x = rodata[6];
            pos2.m_y = rodata[5];
            pos2.m_z = rodata[0];
            fn_69_2848(self->g1fc, &pos2, 0, false, rodata[7]);
            self->g1fc->initializeEntity();
            fn_27_279FA4(self->g1fc);
            fn_27_279FC8(self->g1fc, &matrix, true);
        }
    }

    self->g200 = (NewporkGround*)fn_27_27BDB8(4, base + 0x1a8);
    if (self->g200) {
        self->addGround(self->g200);
        fn_27_27BF44(self->g200, 0, 0, 20, 22);
        ((TargetGround*)self->g200)->setTarget((char*)self->g200 + 0x188);
        self->g200->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g200->setStageData(self->m_stageData);
    }

    self->g204 = (NewporkGround*)fn_27_27BDB8(4, base + 0x1c8);
    if (self->g204) {
        self->addGround(self->g204);
        fn_27_27BF44(self->g204, 0, 0, 20, 24);
        ((TargetGround*)self->g204)->setTarget((char*)self->g204 + 0x188);
        self->g204->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        self->g204->setStageData(self->m_stageData);
    }

    grCollision* collision;
    self->createCollision(self->archive, 2, 0);
    if (self->g1d8) {
        unsigned long node;
        unsigned int count;
        self->g1d8->getNodeIndex(&node, 0, base + 0x88);
        collision = self->g1d8->m_collision;
        if (collision) {
            count = *(unsigned short*)&collision->m_jointLen;
            unsigned int i;
            for (i = 0; i != count; ++i) {
                grCollisionJoint* joint = getJoint__11grCollisionFUs(collision, i);
                if (joint &&
                    *(Ground**)((char*)joint + 0x58) == self->g1d8 &&
                    node == joint->m_nodeIndex) {
                    self->joint34c = joint;
                    break;
                }
            }
        }
    }

    self->initCameraParam();
    void* data = self->archive->getData((ARCNodeType)2, 100, (unsigned short)0xfffe);
    if (data) {
        nw4r::g3d::ResFile file(data);
        self->createStagePositions(&file);
    } else {
        self->createStagePositions();
    }

    self->createWind2ndOnly();
    self->loadStageAttrParam(self->archive, 30);
    self->registScnAnim(
        (nw4r::g3d::ResFileData*)self->archive->getData((ARCNodeType)5, 0, (unsigned short)0xfffe),
        0);
    self->initPosPokeTrainer(1, 0);
    self->createObjPokeTrainer(self->archive, 101, base + 0x1e8,
                               self->m_pokeTrainerPos, 0);

    self->value224 = *(int*)base;
    self->value228 = 0;
    self->value23c = *(int*)base;
    self->value240 = 0;
    self->value250 = *(int*)base;
    self->value254 = 0;
}
