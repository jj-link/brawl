#pragma force_active on

struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    int field_01a0;
};

struct Ground {
    char pad_0000[0x3c];
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36)
    virtual void init(int, int, int);
    SLOT(38)
    virtual void bind(void*);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
    SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64)
    virtual void setVal(float);
    SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73)
    SLOT(74) SLOT(75) SLOT(76) SLOT(77)
    SLOT(78) SLOT(79) SLOT(80) SLOT(81)
    SLOT(82) SLOT(83) SLOT(84) SLOT(85)
    SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93)
    SLOT(94) SLOT(95) SLOT(96) SLOT(97)
    SLOT(98) SLOT(99) SLOT(100) SLOT(101)
    SLOT(102) SLOT(103) SLOT(104) SLOT(105)
    SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112)
    virtual void setPtrA(char*);
    virtual void setFlag(unsigned char);
    virtual void setPtrB(char*);
    SLOT(116) SLOT(117) SLOT(118) SLOT(119)
    SLOT(120) SLOT(121)
    virtual void setIdx(int);
#undef SLOT
};

extern "C" {
extern char lbl_70_data_0[];
extern float lbl_70_rodata_10;

Ground* fn_70_5F0C(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_70_13DC(Stage* stage, int kind) {
    char* data = lbl_70_data_0;
    void* archive = stage->field_009c;
    Ground* ground;
    char* ptr;
    unsigned char mask;
    int count;
    float val;

    if (archive) {
        val = lbl_70_rodata_10;
        ptr = 0;
        mask = 0;
        switch (kind) {
        case 8:
            ground = fn_70_5F0C(6, data + 0x5e4, data + 0x5ec);
            mask |= 0xf;
            ptr = (char*)stage + 0x26c;
            count = 0;
            break;
        case 9:
            ground = fn_70_5F0C(0xf, data + 0x5fc, data + 0x608);
            ptr = (char*)stage + 0x274;
            count = 1;
            break;
        case 10:
            ground = fn_70_5F0C(0x10, data + 0x5fc, data + 0x618);
            mask |= 0x18;
            ptr = (char*)stage + 0x274;
            count = 2;
            break;
        case 11:
            ground = fn_70_5F0C(0xc, data + 0x62c, data + 0x63c);
            val = *(float*)((char*)archive + 0x10);
            ptr = (char*)stage + 0x27c;
            count = 3;
            break;
        default:
            ground = 0;
            break;
        }

        if (ground) {
            addGround__5StageFP6Ground(stage, ground);
            ground->init(stage->field_01a0, 0, 0);
            ground->bind(stage->field_009c);
            ground->setPtrA((char*)stage + 0x1d8);
            ground->setFlag(mask);
            ground->setPtrB(ptr);
            ground->setIdx(count);
            ground->setVal(val);
        }
    }
}
}