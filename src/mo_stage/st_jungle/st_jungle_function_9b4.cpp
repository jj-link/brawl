#pragma force_active on
struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
#define S(n) virtual void s##n();
    S(4) S(5) S(6) S(7) S(8) S(9) S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19) S(20)
    S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28) S(29) S(30) S(31) S(32) S(33) S(34) S(35) S(36) S(37) S(38)
    virtual void startup(void*, int, int);
    S(40)
    virtual void setData(void*);
    S(42) S(43) S(44) S(45) S(46) S(47) S(48) S(49) S(50) S(51) S(52) S(53) S(54) S(55) S(56) S(57)
    S(58) S(59) S(60) S(61) S(62) S(63) S(64) S(65) S(66) S(67) S(68) S(69) S(70) S(71) S(72) S(73)
    S(74) S(75) S(76) S(77) S(78) S(79) S(80) S(81) S(82) S(83) S(84) S(85) S(86) S(87) S(88) S(89)
    S(90) S(91) S(92) S(93) S(94) S(95) S(96) S(97) S(98) S(99) S(100) S(101) S(102) S(103) S(104) S(105)
    S(106) S(107) S(108) S(109) S(110) S(111) S(112) S(113) S(114) S(115) S(116) S(117)
#undef S
    virtual void setPosA(void*);
    virtual void setPosB(void*);
    virtual void setPosC(void*);
    virtual void setPosD(void*);
    virtual void setPosE(void*);
    virtual void s123();
    virtual void setPosF(void*);
    virtual void setPosG(void*);
    void setEnableCollisionStatus(bool);
};

struct gfArchive;

struct Stage {
    char pad0[0x9c];
    void* field9c;
    char pad_a0[0x100];
    gfArchive* field1a0;
    char pad1a4[0x34];
    char field1d8[1];
    void addGround(Ground* g);
    void createCollision(gfArchive* a, int kind, Ground* g);
};

extern "C" {
extern char lbl_51_data_0[];
Ground* fn_51_3F70(int, char*, char*);
Ground* fn_51_B224(int, char*, char*);
Ground* fn_51_C034(int, char*, char*);
Ground* fn_51_C6EC(int, char*, char*);
Ground* fn_51_DB54(int, char*, char*);
Ground* fn_51_E29C(int, char*, char*);
Ground* fn_51_E454(int, char*, char*);
Ground* fn_51_3B04(int, char*, char*);
Ground* fn_51_F4AC(int, char*, char*);
Ground* fn_51_F664(int, char*, char*);
Ground* fn_51_F854(int, char*, char*);
Ground* fn_51_FB28(int, char*, char*);
Ground* fn_51_108B4(int, char*, char*);
Ground* fn_51_10FB4(int, char*, char*);
Ground* fn_51_11398(int, char*, char*);
Ground* fn_51_11908(int, char*, char*);
Ground* fn_51_11AE4(int, char*, char*);

void fn_51_9B4(Stage* arg0, unsigned int arg1) {
    Ground* var_r31;
    void* var_r30;
    void* var_r29;
    void* var_r28;
    void* var_r27;
    int var_r26 = 0;
    void* var_r25 = 0;
    void* var_r24;
    char* data = lbl_51_data_0;

    switch (arg1) {
    case 2:
        var_r31 = fn_51_3F70(7, data + 0x70, data + 0x80);
        var_r30 = (char*)arg0 + 0x1f0;
        var_r24 = (char*)arg0 + 0x434;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x1e;
        break;
    case 3:
        var_r31 = fn_51_B224(8, data + 0x98, data + 0xa8);
        var_r30 = (char*)arg0 + 0x1fc;
        var_r29 = (char*)arg0 + 0x28c;
        var_r25 = (char*)arg0 + 0x441;
        var_r24 = (char*)arg0 + 0x435;
        var_r28 = 0;
        var_r26 = 0x1f;
        break;
    case 4:
        var_r31 = fn_51_C034(9, data + 0xbc, data + 0xd0);
        var_r30 = (char*)arg0 + 0x28c;
        var_r25 = (char*)arg0 + 0x441;
        var_r24 = (char*)arg0 + 0x435;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x20;
        break;
    case 5:
        var_r31 = fn_51_C6EC(0xa, data + 0xe8, data + 0xf8);
        var_r30 = (char*)arg0 + 0x208;
        var_r29 = (char*)arg0 + 0x298;
        var_r25 = (char*)arg0 + 0x442;
        var_r24 = (char*)arg0 + 0x436;
        var_r28 = 0;
        var_r26 = 0x21;
        break;
    case 6:
        var_r31 = fn_51_DB54(0xb, data + 0x10c, data + 0x120);
        var_r30 = (char*)arg0 + 0x298;
        var_r25 = (char*)arg0 + 0x442;
        var_r24 = (char*)arg0 + 0x436;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x22;
        break;
    case 7:
        var_r31 = fn_51_E29C(0xc, data + 0x138, data + 0x148);
        var_r30 = (char*)arg0 + 0x220;
        var_r29 = (char*)arg0 + 0x2bc;
        var_r28 = (char*)arg0 + 0x3ac;
        var_r24 = (char*)arg0 + 0x438;
        var_r26 = 0x23;
        break;
    case 8:
        var_r31 = fn_51_E454(0xd, data + 0x15c, data + 0x170);
        var_r30 = (char*)arg0 + 0x2bc;
        var_r24 = (char*)arg0 + 0x438;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x24;
        break;
    case 9:
        var_r31 = fn_51_3B04(0xe, data + 0x188, data + 0x198);
        var_r30 = (char*)arg0 + 0x22c;
        var_r24 = (char*)arg0 + 0x439;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x25;
        break;
    case 10:
        var_r31 = fn_51_F4AC(0xf, data + 0x1b0, data + 0x1c0);
        var_r30 = (char*)arg0 + 0x238;
        var_r29 = (char*)arg0 + 0x2c8;
        var_r28 = (char*)arg0 + 0x3c4;
        var_r24 = (char*)arg0 + 0x439;
        var_r26 = 0x26;
        break;
    case 11:
        var_r31 = fn_51_F664(0x10, data + 0x1d4, data + 0x1e8);
        var_r30 = (char*)arg0 + 0x2c8;
        var_r24 = (char*)arg0 + 0x43a;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x27;
        break;
    case 12:
        var_r31 = fn_51_F854(0x11, data + 0x1fc, data + 0x210);
        var_r30 = (char*)arg0 + 0x2d4;
        var_r24 = (char*)arg0 + 0x43a;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x28;
        break;
    case 13:
        var_r31 = fn_51_FB28(0x12, data + 0x228, data + 0x238);
        var_r30 = (char*)arg0 + 0x244;
        var_r29 = (char*)arg0 + 0x2e0;
        var_r25 = (char*)arg0 + 0x444;
        var_r24 = (char*)arg0 + 0x43b;
        var_r28 = 0;
        var_r26 = 0x29;
        break;
    case 14:
        var_r31 = fn_51_108B4(0x13, data + 0x24c, data + 0x260);
        var_r30 = (char*)arg0 + 0x2e0;
        var_r25 = (char*)arg0 + 0x444;
        var_r24 = (char*)arg0 + 0x43b;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2a;
        break;
    case 15:
        var_r31 = fn_51_10FB4(0x14, data + 0x278, data + 0x288);
        var_r30 = (char*)arg0 + 0x250;
        var_r29 = (char*)arg0 + 0x2f8;
        var_r24 = (char*)arg0 + 0x43c;
        var_r28 = 0;
        var_r26 = 0x2b;
        break;
    case 16:
        var_r31 = fn_51_3B04(0x15, data + 0x29c, data + 0x2b0);
        var_r30 = (char*)arg0 + 0x2f8;
        var_r24 = (char*)arg0 + 0x43c;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2c;
        break;
    case 17:
        var_r31 = fn_51_3B04(0x15, data + 0x29c, data + 0x2c4);
        var_r30 = (char*)arg0 + 0x304;
        var_r24 = (char*)arg0 + 0x43c;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2c;
        break;
    case 18:
        var_r31 = fn_51_3B04(0x15, data + 0x29c, data + 0x2d8);
        var_r30 = (char*)arg0 + 0x310;
        var_r24 = (char*)arg0 + 0x43c;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2c;
        break;
    case 19:
        var_r31 = fn_51_3B04(0x15, data + 0x29c, data + 0x2ec);
        var_r30 = (char*)arg0 + 0x31c;
        var_r24 = (char*)arg0 + 0x43c;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2c;
        break;
    case 20:
        var_r31 = fn_51_11398(0x16, data + 0x300, data + 0x310);
        var_r30 = (char*)arg0 + 0x25c;
        var_r29 = (char*)arg0 + 0x328;
        var_r27 = (char*)arg0 + 0x3d0;
        var_r25 = (char*)arg0 + 0x44c;
        var_r24 = (char*)arg0 + 0x43d;
        var_r28 = 0;
        var_r26 = 0x2d;
        break;
    case 21:
        var_r31 = fn_51_3B04(0x17, data + 0x328, data + 0x338);
        var_r30 = (char*)arg0 + 0x268;
        var_r24 = (char*)arg0 + 0x43e;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2e;
        break;
    case 22:
        var_r31 = fn_51_11908(0x18, data + 0x350, data + 0x360);
        var_r30 = (char*)arg0 + 0x274;
        var_r29 = (char*)arg0 + 0x358;
        var_r24 = (char*)arg0 + 0x43f;
        var_r28 = 0;
        break;
    case 23:
        var_r31 = fn_51_11AE4(0x19, data + 0x374, data + 0x388);
        var_r30 = (char*)arg0 + 0x358;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2f;
        var_r24 = 0;
        break;
    case 24:
        var_r31 = fn_51_11AE4(0x19, data + 0x374, data + 0x39c);
        var_r30 = (char*)arg0 + 0x370;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x2f;
        var_r24 = 0;
        break;
    case 25:
        var_r31 = fn_51_3B04(0x1a, data + 0x3b0, data + 0x3c0);
        var_r30 = (char*)arg0 + 0x280;
        var_r24 = (char*)arg0 + 0x440;
        var_r29 = 0;
        var_r28 = 0;
        var_r26 = 0x30;
        break;
    default:
        var_r31 = 0;
        var_r30 = 0;
        var_r29 = 0;
        var_r28 = 0;
        break;
    }

    if (var_r31 != 0) {
        arg0->addGround(var_r31);
        var_r31->startup(arg0->field1a0, 0, 0);
        var_r31->setData(arg0->field9c);
        var_r31->setPosA(var_r30);
        var_r31->setPosB(var_r29);
        var_r31->setPosC(var_r28);
        var_r31->setPosD(arg0->field1d8);
        var_r31->setPosE(var_r27);
        var_r31->setPosF(var_r25);
        var_r31->setPosG(var_r24);
        if (var_r26 != 0) {
            arg0->createCollision(arg0->field1a0, var_r26, var_r31);
        }
        var_r31->setEnableCollisionStatus(1);
    }
}
}
