#pragma force_active on
struct GroundBase {
    char pad[0x3c];
};

class Ground : public GroundBase {
public:
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
    virtual void startup(void*, int, int);
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
    SLOT(80) SLOT(81) SLOT(82) SLOT(83)
    SLOT(84) SLOT(85) SLOT(86) SLOT(87)
    SLOT(88) SLOT(89) SLOT(90) SLOT(91)
    SLOT(92) SLOT(93) SLOT(94) SLOT(95)
    SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103)
    SLOT(104) SLOT(105) SLOT(106) SLOT(107)
    SLOT(108) SLOT(109) SLOT(110) SLOT(111)
    SLOT(112) SLOT(113) SLOT(114) SLOT(115)
    virtual void setPosition(void*);
    virtual void setFlag(unsigned char*);
    virtual void setIndex(int);
#undef SLOT
};

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Stage {
    char pad0[0x9c];
    void* data;
    char padA0[0x100];
    void* archive;
    char pad1A4[0x34];
    Vec3f positions[45];
    char pad3F4[5];
    unsigned char flags[3];
};

extern "C" {
extern char lbl_50_data_0[];

Ground* fn_50_AE38(int, const char*, const char*);
Ground* fn_50_B374(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_50_C04(Stage* stage, int kind)
{
    char* strings = lbl_50_data_0;
    Vec3f* pos;
    unsigned char* flag;
    Ground* ground;
    Ground* other;
    int index;
    int position;

    switch (kind) {
    case 12:
        ground = fn_50_AE38(5, strings + 0x128, strings + 0x140);
        index = 0;
        position = 40;
        break;
    case 13:
        ground = fn_50_AE38(6, strings + 0x150, strings + 0x164);
        index = 1;
        position = 41;
        break;
    case 14:
        ground = fn_50_AE38(7, strings + 0x170, strings + 0x180);
        index = 2;
        position = 42;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->archive, 0, 0);
        ground->bind(stage->data);
        ground->setIndex(index);
        pos = &stage->positions[position];
        ground->setPosition(pos);
        flag = &stage->flags[index];
        ground->setFlag(flag);

        other = fn_50_B374(10, strings + 0x18c, strings + 0x1a0);
        if (other) {
            addGround__5StageFP6Ground(stage, other);
            other->startup(stage->archive, 0, 0);
            other->bind(stage->data);
            other->setPosition(pos);
            other->setFlag(flag);
        }
    }
}
}
