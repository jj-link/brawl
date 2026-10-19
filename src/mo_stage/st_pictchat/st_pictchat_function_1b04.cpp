#pragma force_active on
struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    void* field_01a0;
    char pad_01a4[0x24c];
    void* field_03f0;
};

struct GroundPrefix {
    char pad_0000[0x3c];
};

struct Ground : GroundPrefix {
#define UNUSED_SLOT(n) virtual void slot##n();
    UNUSED_SLOT(0) UNUSED_SLOT(1) UNUSED_SLOT(2) UNUSED_SLOT(3)
    UNUSED_SLOT(4) UNUSED_SLOT(5) UNUSED_SLOT(6) UNUSED_SLOT(7)
    UNUSED_SLOT(8) UNUSED_SLOT(9) UNUSED_SLOT(10) UNUSED_SLOT(11)
    UNUSED_SLOT(12) UNUSED_SLOT(13) UNUSED_SLOT(14) UNUSED_SLOT(15)
    UNUSED_SLOT(16) UNUSED_SLOT(17) UNUSED_SLOT(18) UNUSED_SLOT(19)
    UNUSED_SLOT(20) UNUSED_SLOT(21) UNUSED_SLOT(22) UNUSED_SLOT(23)
    UNUSED_SLOT(24) UNUSED_SLOT(25) UNUSED_SLOT(26) UNUSED_SLOT(27)
    UNUSED_SLOT(28) UNUSED_SLOT(29) UNUSED_SLOT(30) UNUSED_SLOT(31)
    UNUSED_SLOT(32) UNUSED_SLOT(33) UNUSED_SLOT(34) UNUSED_SLOT(35)
    UNUSED_SLOT(36)
    virtual void setup(void*, int, int);
    UNUSED_SLOT(40)
    virtual void bind(void*);
    UNUSED_SLOT(42) UNUSED_SLOT(43) UNUSED_SLOT(44) UNUSED_SLOT(45)
    UNUSED_SLOT(46) UNUSED_SLOT(47) UNUSED_SLOT(48) UNUSED_SLOT(49)
    UNUSED_SLOT(50) UNUSED_SLOT(51) UNUSED_SLOT(52) UNUSED_SLOT(53)
    UNUSED_SLOT(54) UNUSED_SLOT(55) UNUSED_SLOT(56) UNUSED_SLOT(57)
    UNUSED_SLOT(58) UNUSED_SLOT(59) UNUSED_SLOT(60) UNUSED_SLOT(61)
    UNUSED_SLOT(62) UNUSED_SLOT(63) UNUSED_SLOT(64) UNUSED_SLOT(65)
    UNUSED_SLOT(66) UNUSED_SLOT(67) UNUSED_SLOT(68) UNUSED_SLOT(69)
    UNUSED_SLOT(70) UNUSED_SLOT(71) UNUSED_SLOT(72) UNUSED_SLOT(73)
    UNUSED_SLOT(74) UNUSED_SLOT(75) UNUSED_SLOT(76) UNUSED_SLOT(77)
    UNUSED_SLOT(78) UNUSED_SLOT(79) UNUSED_SLOT(80) UNUSED_SLOT(81)
    virtual void startup(void*);
    UNUSED_SLOT(83) UNUSED_SLOT(84) UNUSED_SLOT(85) UNUSED_SLOT(86)
    UNUSED_SLOT(87) UNUSED_SLOT(88) UNUSED_SLOT(89) UNUSED_SLOT(90)
    UNUSED_SLOT(91) UNUSED_SLOT(92) UNUSED_SLOT(93) UNUSED_SLOT(94)
    UNUSED_SLOT(95) UNUSED_SLOT(96) UNUSED_SLOT(97) UNUSED_SLOT(98)
    UNUSED_SLOT(99) UNUSED_SLOT(100) UNUSED_SLOT(101) UNUSED_SLOT(102)
    UNUSED_SLOT(103) UNUSED_SLOT(104) UNUSED_SLOT(105) UNUSED_SLOT(106)
    UNUSED_SLOT(107) UNUSED_SLOT(108) UNUSED_SLOT(109) UNUSED_SLOT(110)
    UNUSED_SLOT(111) UNUSED_SLOT(112) UNUSED_SLOT(113) UNUSED_SLOT(114)
    UNUSED_SLOT(115) UNUSED_SLOT(116) UNUSED_SLOT(117) UNUSED_SLOT(118)
    virtual void text(char*);
    virtual void number(int);
    virtual void ptr1(char*);
    virtual void ptr2(char*);
    virtual void ptr3(char*);
#undef UNUSED_SLOT
};

extern "C" {
extern char lbl_73_data_0[];
Ground* fn_73_D5AC(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_73_1B04(Stage* stage, int kind) {
    Ground* ground;
    char* arg1;
    int count;
    char* arg2;
    char* data = lbl_73_data_0;

    switch (kind) {
    case 0x25:
        ground = fn_73_D5AC(3, data + 0x6e4, data + 0x7f0);
        arg1 = (char*)stage + 0x3f4;
        arg2 = (char*)stage + 0x40c;
        count = 8;
        break;
    case 0x26:
        ground = fn_73_D5AC(3, data + 0x6e4, data + 0x804);
        arg1 = (char*)stage + 0x400;
        arg2 = (char*)stage + 0x40d;
        count = 8;
        break;
    default:
        break;
    }

    if (ground) {
        ground->startup(stage->field_03f0);
        addGround__5StageFP6Ground(stage, ground);
        ground->setup(stage->field_01a0, 0, 0);
        ground->bind(stage->field_009c);
        ground->text((char*)stage + 0x1e1);
        ground->number(count);
        ground->ptr1(arg1);
        ground->ptr2(arg2);
        ground->ptr3((char*)stage + 0x40e);
    }
}
}
