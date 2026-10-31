#pragma force_active on
struct grCollStatus;
struct grCollisionJoint;

class GroundBase {
public:
    char pad0[0x3C];
};

class Ground : public GroundBase {
public:
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
    virtual void receiveCollMsg_Landing(grCollStatus*, grCollisionJoint*, bool);
    virtual void receiveCollMsg_Heading(grCollStatus*, grCollisionJoint*);
    virtual void receiveCollMsg_Wall(grCollStatus*, grCollisionJoint*, bool);
    virtual void receiveCollMsg_Attack(grCollStatus*, grCollisionJoint*);
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
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();

    void receiveCollMsg(int, grCollStatus*, grCollisionJoint*);
};

void Ground::receiveCollMsg(int arg, grCollStatus* status, grCollisionJoint* joint) {
    switch (arg) {
        case 1:
            this->receiveCollMsg_Landing(status, joint, true);
            break;
        case 0:
            this->receiveCollMsg_Landing(status, joint, false);
            break;
        case 2:
            this->receiveCollMsg_Heading(status, joint);
            break;
        case 3:
            this->receiveCollMsg_Wall(status, joint, true);
            break;
        case 4:
            this->receiveCollMsg_Wall(status, joint, false);
            break;
        case 5:
            this->receiveCollMsg_Attack(status, joint);
            break;
    }
}