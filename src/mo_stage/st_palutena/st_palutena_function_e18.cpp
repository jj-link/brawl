#pragma force_active on
struct Stage {
    char pad0[0x9c];
    void* p9c;
    char padA0[0x100];
    void* p1a0;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
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
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_67_2168();
    virtual void startup(void* archive, int unk1, int unk2);
    virtual void slot38();
    virtual void setValue(void* value);
    virtual void fn_67_2160();
    virtual void fn_67_888();
};

extern "C" {
extern char lbl_67_data_0[];
Ground* fn_67_C0FC(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_67_E18(Stage* arg0, int arg1) {
    Ground* var_r31;
    char* data = lbl_67_data_0;

    switch (arg1) {
    case 35:
        var_r31 = fn_67_C0FC(0x32, data + 0x3BC, data + 0x3C8);
        break;
    case 36:
        var_r31 = fn_67_C0FC(0x33, data + 0x3E4, data + 0x3F0);
        break;
    case 37:
        var_r31 = fn_67_C0FC(0x34, data + 0x40C, data + 0x418);
        break;
    case 38:
        var_r31 = fn_67_C0FC(0x35, data + 0x434, data + 0x440);
        break;
    case 39:
        var_r31 = fn_67_C0FC(0x36, data + 0x45C, data + 0x468);
        break;
    case 40:
        var_r31 = fn_67_C0FC(0x37, data + 0x484, data + 0x490);
        break;
    case 41:
        var_r31 = fn_67_C0FC(0x38, data + 0x4AC, data + 0x4B8);
        break;
    case 42:
        var_r31 = fn_67_C0FC(0x39, data + 0x4D4, data + 0x4E0);
        break;
    case 43:
        var_r31 = fn_67_C0FC(0x3A, data + 0x4FC, data + 0x508);
        break;
    default:
        var_r31 = 0;
        break;
    }
    if (var_r31 != 0) {
        addGround__5StageFP6Ground(arg0, var_r31);
        var_r31->startup(arg0->p1a0, 0, 0);
        var_r31->setValue(arg0->p9c);
        var_r31->fn_67_888();
    }
}
}
