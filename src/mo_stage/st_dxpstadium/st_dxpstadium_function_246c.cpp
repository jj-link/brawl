#pragma force_active on
typedef unsigned char u8;
struct Vec3f { float x, y, z; };
struct Ground {
    char pad[0x3c];
    virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4();
    virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
    virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
    virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24();
    virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29();
    virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34();
    virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
    virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44();
    virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49();
    virtual void u50(); virtual void u51(); virtual void u52();
    virtual void setAnimation(int, int, const char*, int, int);
};
struct Stage {
    char pad[0x615];
    u8 flag;
    u8 player;
    u8 nextPlayer;
};
struct PlayerData { u8 kind; u8 variant; char tail[0x5c - 2]; };
struct MeleeData {
    char pad[0xf];
    u8 unusedFlags : 7;
    bool special : 1;
    char pad2[0x88];
    PlayerData players[4];
};
struct GameGlobal { char pad[8]; MeleeData* melee; };
extern "C" {
Ground* getGround__5StageFi(Stage*, int);
void setDisplay__15grStadiumVisionFb(Ground*, bool);
bool getPlayerPosition__7stMeleeFiP5Vec3f(int, Vec3f*);
extern char lbl_83_data_54[];
extern GameGlobal* g_GameGlobal;
void fn_83_246C(Stage* stage) {
    setDisplay__15grStadiumVisionFb(getGround__5StageFi(stage, 0), false);
    Ground* ground = getGround__5StageFi(stage, 0);
    ground->setAnimation(1, 0, lbl_83_data_54, 0, 0);
    Vec3f position;
    int players[4];
    int* write = players;
    int count = 0;
    players[0] = 0;
    players[1] = 0;
    players[2] = 0;
    players[3] = 0;
    for (int i = 0; i < 4; ++i) {
        if (getPlayerPosition__7stMeleeFiP5Vec3f(i, &position) == true) {
            *write++ = i;
            ++count;
        }
    }
    if (stage->nextPlayer >= count)
        stage->nextPlayer = 0;
    stage->flag = 1;
    int selected = players[stage->nextPlayer];
    ++stage->nextPlayer;
    stage->player = selected;
    MeleeData* melee = g_GameGlobal->melee;
    if (melee->players[stage->player].kind == 0x27 &&
        melee->players[stage->player].variant == 3)
        melee->special = true;
    else
        melee->special = false;
}
}
