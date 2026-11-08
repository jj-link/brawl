#include <st/stage.h>
#pragma force_active on
struct GroundBase { char pad[0x3c]; };
#define SLOT(n) virtual void slot##n();
class PictGround : public GroundBase {
public:
SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36)
virtual void slot37(void*, int, int);
SLOT(38)
virtual void slot39(void*);
SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115)
virtual void slot116(void*);
virtual void slot117(void*);
virtual void slot118(void*);
virtual void slot119(int);
virtual void slot120(int);
};
#undef SLOT
extern "C" {
extern char lbl_73_data_0[];
PictGround* fn_73_F000(int, char*, char*);
void fn_73_1330(Stage* stage, int kind) {
    PictGround* ground;
    char* arg1;
    char* arg2;
    int count;
    int index;
    char* data = lbl_73_data_0;
    switch (kind) {
    case 39:
        ground = fn_73_F000(3, data + 0x6e4, data + 0x6f0);
        arg1 = (char*)stage + 0x388;
        arg2 = (char*)stage + 0x201;
        count = 7;
        index = 0;
        break;
    case 40:
        ground = fn_73_F000(3, data + 0x6e4, data + 0x708);
        arg1 = (char*)stage + 0x394;
        arg2 = (char*)stage + 0x202;
        count = 7;
        index = 1;
        break;
    case 41:
        ground = fn_73_F000(3, data + 0x6e4, data + 0x720);
        arg1 = (char*)stage + 0x3a0;
        arg2 = (char*)stage + 0x203;
        count = 7;
        index = 2;
        break;
    case 42:
        ground = fn_73_F000(3, data + 0x6e4, data + 0x738);
        arg1 = (char*)stage + 0x3ac;
        arg2 = (char*)stage + 0x204;
        count = 7;
        index = 3;
        break;
    case 43:
        ground = fn_73_F000(3, data + 0x6e4, data + 0x750);
        arg1 = (char*)stage + 0x3b8;
        arg2 = (char*)stage + 0x205;
        count = 7;
        index = 4;
        break;
    case 44:
        ground = fn_73_F000(3, data + 0x6e4, data + 0x768);
        arg1 = (char*)stage + 0x3c4;
        arg2 = (char*)stage + 0x206;
        count = 7;
        index = 5;
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround((Ground*)ground);
        ground->slot37(*(void**)((char*)stage + 0x1a0), 0, 0);
        ground->slot39(*(void**)((char*)stage + 0x9c));
        ground->slot116(arg1);
        ground->slot118((char*)stage + 0x1e1);
        ground->slot119(count);
        ground->slot117(arg2);
        switch (kind) {
        case 39: case 40: case 41: case 42: case 43: case 44:
            ground->slot120(index);
            break;
        }
    }
}
}