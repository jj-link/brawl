#include <types.h>
#pragma force_active on

struct Ret { s32 a; s32 b; };
struct ClazzPad { s32 a; s32 b; };

#define VM(n) virtual s32 m##n();

class Clazz : public ClazzPad {
public:
    VM(0)VM(1)VM(2)VM(3)VM(4)VM(5)VM(6)VM(7)
    VM(8)VM(9)VM(10)VM(11)VM(12)VM(13)VM(14)VM(15)
    VM(16)VM(17)VM(18)VM(19)VM(20)VM(21)VM(22)VM(23)
    VM(24)VM(25)VM(26)VM(27)VM(28)VM(29)VM(30)VM(31)
    VM(32)VM(33)VM(34)VM(35)VM(36)VM(37)VM(38)VM(39)
    VM(40)VM(41)VM(42)VM(43)VM(44)VM(45)VM(46)VM(47)
    VM(48)VM(49)VM(50)VM(51)VM(52)VM(53)VM(54)VM(55)
    VM(56)VM(57)VM(58)VM(59)VM(60)VM(61)VM(62)VM(63)
    VM(64)VM(65)VM(66)VM(67)VM(68)VM(69)VM(70)VM(71)
    VM(72)VM(73)VM(74)VM(75)VM(76)VM(77)VM(78)VM(79)
    VM(80)VM(81)VM(82)VM(83)VM(84)VM(85)VM(86)VM(87)
    VM(88)VM(89)VM(90)VM(91)VM(92)VM(93)VM(94)VM(95)
    VM(96)VM(97)VM(98)VM(99)VM(100)VM(101)VM(102)VM(103)
    VM(104)VM(105)VM(106)VM(107)VM(108)VM(109)VM(110)VM(111)
    VM(112)VM(113)VM(114)VM(115)VM(116)VM(117)VM(118)VM(119)
    VM(120)VM(121)VM(122)VM(123)VM(124)VM(125)VM(126)VM(127)
    VM(128)VM(129)VM(130)VM(131)VM(132)VM(133)
    virtual u32 m134();
    VM(135)VM(136)VM(137)VM(138)VM(139)VM(140)VM(141)VM(142)
    virtual Ret m143();
};
#undef VM

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_41_158E8(void*, void*);
void fn_41_65D0(void*);
extern const char lbl_41_data_644[], lbl_41_data_6A8[];

void fn_41_58CF8(void* self) {
    unsigned char* p = (unsigned char*)self;
    Clazz* obj = *(Clazz**)(*(unsigned char**)(p + 0x1B4) + 0x10);
    if (obj->m134() == 1) {
        Ret a;
        Ret b;
        a = obj->m143();
        b = a;
        void* dyn = __dynamic_cast(*(void**)(*(unsigned char**)(p + 0x1B4) + 0x7C), 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        fn_41_158E8(dyn, &b);
    }
    fn_41_65D0(self);
}
}
