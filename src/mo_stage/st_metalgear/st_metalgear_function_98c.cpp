#include <st/stage.h>
#pragma force_active on

struct GroundPrefix { char pad[0x3c]; };
class MetalGround : public GroundPrefix {
public:
#define SLOT(n) virtual void slot##n();
SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36)
virtual void startup(void*, int, int);
SLOT(38)
virtual void bind(void*);
SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118)
virtual void slot119(void*);
virtual void slot120(void*);
virtual void slot121(void*);
virtual void fn_71_B44(int);
#undef SLOT
};
extern "C" {
extern char lbl_71_data_0[];
MetalGround* fn_71_6A98(int, char*, char*);
void fn_71_98C(Stage* stage, int kind) {
    MetalGround* ground;
    char* arg1;
    char* arg2;
    int count;
    char* data = lbl_71_data_0;
    switch (kind) {
    case 3:
        ground = fn_71_6A98(1, data + 0xc8, data + 0xdc);
        arg1 = (char*)stage + 0x2b0;
        arg2 = (char*)stage + 0x2b4;
        count = 0;
        break;
    case 5:
        ground = fn_71_6A98(3, data + 0xf4, data + 0x108);
        arg1 = (char*)stage + 0x2b2;
        arg2 = (char*)stage + 0x2b8;
        count = 2;
        break;
    case 4:
        ground = fn_71_6A98(2, data + 0x120, data + 0x138);
        arg1 = (char*)stage + 0x2b1;
        arg2 = 0;
        count = 1;
        break;
    case 6:
        ground = fn_71_6A98(4, data + 0x150, data + 0x168);
        arg1 = (char*)stage + 0x2b3;
        arg2 = 0;
        count = 3;
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround((Ground*)ground);
        ground->startup(*(void**)((char*)stage + 0x1a0), 0, 0);
        ground->bind(*(void**)((char*)stage + 0x9c));
        ground->slot119((char*)stage + 0x1e0);
        ground->slot120(arg2);
        ground->slot121(arg1);
        ground->fn_71_B44(count);
    }
}
}