#pragma force_active on
#include <types.h>

extern "C" {
extern char lbl_50_data_12F0[];
extern float lbl_50_rodata_8C;
char* strcpy(char*, const char*);
char* itoa(int, char*, int);
u32 strlen(const char*);
char* strncpy(char*, const char*, u32);
int atoi(const char*);
}

struct Ground_base { char pad[0x3c]; };
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
    virtual void fn_50_39C4();
    virtual void fn_50_3A1C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_50_2324();
    virtual void startup();
    virtual void setNode();
    virtual void fn_50_690();
    virtual void fn_50_231C();
    virtual void fn_50_2318();
    virtual void fn_50_1F70();
    virtual void fn_50_2310();
    virtual void fn_50_2304();
    virtual void fn_50_22F4();
    virtual void fn_50_22E4();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_50_22E0();
    virtual void fn_50_22DC();
    virtual void fn_50_22D4();
    virtual void setMotionRatio();
    virtual void setMotionFrame(float, u32);
    u8 pad40[0x168 - 0x40];
    u32* p168;
    u32 p16c;
    u8 p170;
};

extern "C" void fn_50_3A9C(Ground* self) {
    char buf[8];
    char num[0x40];
    u32 len;
    u8 var;
    u8 kind;

    if (*self->p168 != self->p16c) {
        self->p16c = *self->p168;
        var = 0;
        strcpy(buf, lbl_50_data_12F0);
        itoa(*self->p168, num, 10);
        len = strlen(num);
        kind = self->p170;
        switch (kind) {
        case 2:
            if (len >= 1) {
                strncpy(buf, &num[len - 1], 1);
                var = atoi(buf);
            }
            break;
        case 3:
            if (len >= 2) {
                strncpy(buf, &num[len - 2], 1);
                var = atoi(buf);
            }
            break;
        case 4:
            if (len >= 3) {
                strncpy(buf, &num[len - 3], 1);
                var = atoi(buf);
            }
            break;
        case 5:
            if (len >= 4) {
                strncpy(buf, &num[len - 4], 1);
                var = atoi(buf);
            }
            break;
        case 6:
            if (len >= 5) {
                strncpy(buf, &num[len - 5], 1);
                var = atoi(buf);
            }
            break;
        case 7:
            if (len >= 6) {
                strncpy(buf, &num[len - 6], 1);
                var = atoi(buf);
            }
            break;
        }
        if (var == 0) {
            self->setMotionFrame(lbl_50_rodata_8C, 0);
            return;
        }
        self->setMotionFrame((float)(int)(var - 1), 0);
    }
}