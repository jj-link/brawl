#include <types.h>
#pragma force_active on

struct ftManager;

extern "C" {
extern ftManager* g_ftManager;
int getPlayerNo__9ftManagerFi(ftManager*, int);
}

struct TargetBase {
    unsigned char padding[0x3C];
};

struct Target : TargetBase {
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
    virtual void setEnabled(int);
};

struct Player {
    unsigned char padding[0x5A];
    unsigned char enabled;
    unsigned char end;
};

struct PlayerData {
    unsigned char padding[0x40];
    Player players[4];
};

struct State {
    unsigned char padding0[0x0C];
    PlayerData* players;
    unsigned char padding1[0x20];
    Target* target;
};

extern "C" void fn_27_27E950(State* self, int entryId) {
    if (self->target) {
        int playerNo = getPlayerNo__9ftManagerFi(g_ftManager, entryId);
        if (self->players->players[playerNo].enabled) {
            self->target->setEnabled(1);
        }
    }
}
