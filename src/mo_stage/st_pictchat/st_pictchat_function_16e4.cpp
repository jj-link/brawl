#pragma force_active on
struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    void* field_01a0;
    char pad_01a4[0x22c];
    int field_03d0;
};

struct GroundPrefix {
    char pad_0000[0x3c];
};

struct Ground : GroundPrefix {
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
    virtual void setup(void*, int, int);
    SLOT(38)
    virtual void bind(void*);
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
    SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51)
    SLOT(52) SLOT(53) SLOT(54) SLOT(55)
    SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63)
    SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    SLOT(68) SLOT(69) SLOT(70) SLOT(71)
    SLOT(72) SLOT(73) SLOT(74) SLOT(75)
    SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    virtual void val(int);
    SLOT(81) SLOT(82) SLOT(83) SLOT(84)
    SLOT(85) SLOT(86) SLOT(87) SLOT(88)
    SLOT(89) SLOT(90) SLOT(91) SLOT(92)
    SLOT(93) SLOT(94) SLOT(95) SLOT(96)
    SLOT(97) SLOT(98) SLOT(99) SLOT(100)
    SLOT(101) SLOT(102) SLOT(103) SLOT(104)
    SLOT(105) SLOT(106) SLOT(107) SLOT(108)
    SLOT(109) SLOT(110) SLOT(111) SLOT(112)
    SLOT(113) SLOT(114) SLOT(115)
    virtual void ptr1(char*);
    virtual void ptr2(char*);
    virtual void num(int);
    virtual void ptr3(char*);
#undef SLOT
};

extern "C" {
extern char lbl_73_data_0[];
Ground* fn_73_D15C(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_73_16E4(Stage* stage, int kind) {
    Ground* ground;
    int value;
    char* arg1;
    int count;
    char* data = lbl_73_data_0;

    switch (kind) {
    case 0x23:
        ground = fn_73_D15C(0xE4, data + 0x790, data + 0x7AC);
        value = stage->field_03d0;
        arg1 = (char*)stage + 0x3D4;
        count = 0x16;
        break;
    case 0x24:
        ground = fn_73_D15C(0xE5, data + 0x7C0, data + 0x7DC);
        arg1 = (char*)stage + 0x3E0;
        count = 0x16;
        value = stage->field_03d0 + 0x5C;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->val(value);
        ground->setup(stage->field_01a0, 0, 0);
        ground->bind(stage->field_009c);
        ground->ptr2((char*)stage + 0x1e1);
        ground->num(count);
        ground->ptr1(arg1);
        ground->ptr3((char*)stage + 0x3ec);
    }
}
}