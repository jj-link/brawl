#pragma force_active on
extern "C" {
float randf__Fv();
extern const float lbl_50_rodata_190;
}

struct Anim {
    char pad[0x4c];
    float unk4c;
    float unk50;
};

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
    virtual void fn_50_9F4C();
    virtual void fn_50_9FD0();
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
    virtual Anim* fn_50_231C();  // offset 0xa8
    char pad40[0x164 - 0x40];
    float* unk164;
    char pad168[0x178 - 0x168];
    float unk178;
    float unk17c;
    float unk180;
    char pad184[0x190 - 0x184];
    unsigned char unk190;
    unsigned char unk191;
    unsigned char unk192;
};

extern "C" void fn_50_ABFC(Ground* arg0) {
    Anim* a = arg0->fn_50_231C();

    if (a != 0) {
        int var_r30 = 0;
        unsigned int var_r29 = 0;
        float total = a->unk4c + a->unk50;
        if (randf__Fv() < a->unk4c / total) {
            var_r29 = 1;
        }
        switch (arg0->unk191) {
        case 0:
            switch (arg0->unk192) {
            case 0:
                var_r30 = 3;
                if (var_r29 == 0) var_r30 = 1;
                break;
            case 1:
                var_r30 = 2;
                if (var_r29 == 0) var_r30 = 0;
                break;
            case 2:
                var_r30 = 1;
                if (var_r29 == 0) var_r30 = 3;
                break;
            case 3:
                if (randf__Fv() < lbl_50_rodata_190) var_r30 = 0;
                else var_r30 = 4;
                if (var_r29 == 0) var_r30 = 2;
                break;
            case 4:
                var_r30 = 3;
                break;
            }
            break;
        case 1:
            switch (arg0->unk192) {
            case 0:
                var_r30 = 1;
                break;
            case 1:
                var_r30 = 0;
                if (var_r29 == 0) var_r30 = 3;
                break;
            case 2:
                var_r30 = 3;
                break;
            case 3:
                if (randf__Fv() < lbl_50_rodata_190) var_r30 = 2;
                else var_r30 = 4;
                if (var_r29 == 0) var_r30 = 3;
                break;
            case 4:
                var_r30 = 3;
                if (var_r29 == 0) var_r30 = 6;
                break;
            case 5:
                var_r30 = 6;
                break;
            case 6:
                var_r30 = 5;
                if (var_r29 == 0) var_r30 = 4;
                break;
            }
            break;
        }

        {
            float* e = (float*)((char*)arg0->unk164 + var_r30 * 12);
            arg0->unk178 = e[0];
            arg0->unk17c = e[1];
            arg0->unk180 = e[2];
        }
        arg0->unk192 = (unsigned char)var_r30;
        if (var_r29 == 1) {
            arg0->unk190 = 0;
        } else {
            arg0->unk190 = 1;
        }
    }
}
