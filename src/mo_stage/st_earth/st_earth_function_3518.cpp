#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_66_2F44();
    virtual void fn_66_3040();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_66_3518();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void fn_66_2F9C();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3*, unsigned long, unsigned long);

    char pad40[0x110];
    unsigned char state;
    char pad151[7];
    unsigned int value;
    float timer;
    Vec3 left;
    Vec3 right;
    Vec3 offsets[5];
    float weights[5];
    float speed;
    float progress;
    unsigned long nodes[5];
};

struct EarthConstants {
    float zero;
    float unused04;
    float unused08;
    float quarter;
    float unused10;
    float unused14;
    float unused18;
    float timer;
    float maxDistance;
    float margin;
    float speed;
};

extern "C" {
    extern const EarthConstants lbl_66_rodata_78;
    extern float lbl_27_data_547E0;
    void fn_801342C8(void*, Vec2*);
}

extern "C" void fn_66_3518(Ground* self, void* status,
                            unsigned int value, unsigned int kind) {
    const EarthConstants* constants = &lbl_66_rodata_78;
    self->value = value;
    self->timer = constants->timer;

    if (kind == 1) {
        self->offsets[0].x = constants->zero;
        self->offsets[0].y = constants->zero;
        self->offsets[0].z = constants->zero;
        self->weights[0] = constants->zero;
        self->offsets[1].x = constants->zero;
        self->offsets[1].y = constants->zero;
        self->offsets[1].z = constants->zero;
        self->weights[1] = constants->zero;
        self->offsets[2].x = constants->zero;
        self->offsets[2].y = constants->zero;
        self->offsets[2].z = constants->zero;
        self->weights[2] = constants->zero;
        self->offsets[3].x = constants->zero;
        self->offsets[3].y = constants->zero;
        self->offsets[3].z = constants->zero;
        self->weights[3] = constants->zero;
        self->offsets[4].x = constants->zero;
        self->offsets[4].y = constants->zero;
        self->offsets[4].z = constants->zero;
        self->weights[4] = constants->zero;

        Vec2 position;
        Vec3 points[5];

        fn_801342C8(status, &position);
        self->getNodePosition(&points[0], 0, self->nodes[0]);
        self->getNodePosition(&points[1], 0, self->nodes[1]);
        self->getNodePosition(&points[2], 0, self->nodes[2]);
        self->getNodePosition(&points[3], 0, self->nodes[3]);
        self->getNodePosition(&points[4], 0, self->nodes[4]);

        float x = position.x;
        int nearest = -1;
        float distance = constants->maxDistance;
        float delta = nw4r::ut::Abs(x - points[0].x);
        if (delta < distance) {
            distance = delta;
            nearest = 0;
        }
        delta = nw4r::ut::Abs(x - points[1].x);
        if (delta < distance) {
            distance = delta;
            nearest = 1;
        }
        delta = nw4r::ut::Abs(x - points[2].x);
        if (delta < distance) {
            distance = delta;
            nearest = 2;
        }
        delta = nw4r::ut::Abs(x - points[3].x);
        if (delta < distance) {
            distance = delta;
            nearest = 3;
        }
        delta = nw4r::ut::Abs(x - points[4].x);
        if (delta < distance) {
            nearest = 4;
        }

        if (nearest != -1) {
            self->left = points[0];
            self->left.x -= constants->margin;
            self->right = points[4];
            self->right.x += constants->margin;

            float leftDistance = self->left.x - points[nearest].x;
            float rightDistance = self->right.x - points[nearest].x;

            for (unsigned char i = 0; i < 5; ++i) {
                if (nearest == i) {
                    self->weights[i] = constants->zero;
                } else if (nearest < i) {
                    self->weights[i] =
                        (points[i].x - points[nearest].x) / rightDistance;
                } else if (nearest > i) {
                    self->weights[i] =
                        (points[i].x - points[nearest].x) / leftDistance;
                }
            }

            float factor = lbl_27_data_547E0;
            float speed = constants->speed * factor;
            self->state = 2;
            self->progress = constants->quarter;
            self->speed = speed;
        }
    }
}
