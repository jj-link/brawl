#pragma force_active on

extern "C" const float lbl_46_rodata_0;
extern "C" void fn_801109AC(void*);
extern "C" void fn_80110C40(void*, int);
extern "C" void fn_8011097C(void*);

struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
#define V(n) virtual void unused##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
    V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
    V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63)
    V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71)
    V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95)
    V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103)
    V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111)
    V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127)
    V(128) V(129) V(130) V(131) V(132) V(133) V(134) V(135)
    V(136) V(137) V(138) V(139) V(140) V(141) V(142)
    V(143) V(144) V(145) V(146) V(147)
#undef V
    virtual void fn_46_34C8(int, int, float);

    char pad1[0x6ec - 0x40];
    void* arr[10];
    char pad2[0x30];
    unsigned char state;
    unsigned char mode;
    char pad3[2];
    float timer;
};

extern "C" void fn_46_3398(Stage* self, float delta) {
    self->timer -= delta;
    if (self->timer < lbl_46_rodata_0)
        self->timer = lbl_46_rodata_0;

    if (self->state < 10) {
        int r31_val = 0;
        if (self->mode != 0) {
            if (lbl_46_rodata_0 == self->timer) {
                void* ptr1 = self->arr[self->mode];
                if (ptr1) {
                    fn_801109AC(ptr1);
                    void* ptr2 = self->arr[self->mode];
                    fn_80110C40(ptr2, 0);
                }
                void* ptr3 = self->arr[self->state];
                if (ptr3) {
                    fn_8011097C(ptr3);
                }
                self->mode = 0;
            } else {
                r31_val = 1;
            }
        }
        self->fn_46_34C8(self->state, 0, delta);
        self->fn_46_34C8(self->mode, r31_val, delta);
    }
}