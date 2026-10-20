#pragma force_active on
typedef unsigned char u8;

struct Vec3f {
    float x, y, z;
};

struct Ground {
    char pad[0x3c];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void setAnimation(int, int, const char*, int, int);
};

struct Stage {
    char pad[0x6ac];
    int state;
    char pad2[0x34];
    u8 player;
    u8 nextPlayer;
};

struct PlayerData {
    u8 kind;
    u8 variant;
    char tail[0x5c - 2];
};

struct MeleeData {
    char pad[0xf];
    u8 unusedFlags : 7;
    bool special : 1;
    char pad2[0x88];
    PlayerData players[4];
};

struct GameGlobal {
    char pad[8];
    MeleeData* melee;
};

extern "C" {
Ground* getGround__5StageFi(Stage*, int);
void setDisplay__15grStadiumVisionFb(Ground*, bool);
bool getPlayerPosition__7stMeleeFiP5Vec3f(int, Vec3f*);

extern char lbl_59_data_224[];
extern char lbl_59_data_234[];
extern GameGlobal* g_GameGlobal;

void fn_59_2CA0(Stage* stage) {
    setDisplay__15grStadiumVisionFb(getGround__5StageFi(stage, 0), false);

    Ground* ground = getGround__5StageFi(stage, 0);
    ground->setAnimation(1, 0, lbl_59_data_224, 0, 0);
    ground = getGround__5StageFi(stage, 0);
    ground->setAnimation(0, 0, lbl_59_data_234, 0, 0);

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

    stage->state = 1;
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
