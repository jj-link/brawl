#pragma force_active on
typedef unsigned char u8;
struct Data { u8 pad[0x18]; u8 values[10]; };
struct Base {
 u8 pad[0x3c];
#define SLOT(n) virtual void slot##n();
SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29) SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39) SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69) SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79) SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99) SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109) SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118) SLOT(119) SLOT(120) SLOT(121) SLOT(122) SLOT(123) SLOT(124) SLOT(125) SLOT(126) SLOT(127) SLOT(128) SLOT(129) SLOT(130) SLOT(131) SLOT(132) SLOT(133) SLOT(134) SLOT(135) SLOT(136) SLOT(137) SLOT(138) SLOT(139) SLOT(140) SLOT(141) SLOT(142) SLOT(143) SLOT(144)
#undef SLOT
 virtual void method(u8, bool, bool);
};
struct Object : Base { u8 pad1[0x5c]; Data* data; u8 pad2[0x138]; u8 state; };
extern "C" void fn_46_22FC(Object* self) {
    if (self->data == 0) return;
    switch(self->state) {
    case 2: self->method(self->data->values[0],0,1); break;
    case 4: self->method(self->data->values[0],0,1); break;
    case 6: self->method(self->data->values[1],1,1); break;
    case 8: self->method(self->data->values[1],1,1); break;
    case 10: self->method(self->data->values[2],1,1); break;
    case 12: self->method(self->data->values[2],1,1); break;
    case 14: self->method(self->data->values[3],1,1); break;
    case 16: self->method(self->data->values[4],1,1); break;
    case 18: self->method(self->data->values[4],1,1); break;
    case 20: self->method(self->data->values[5],1,1); break;
    case 22: self->method(self->data->values[6],1,1); break;
    case 24: self->method(self->data->values[6],1,1); break;
    case 26: self->method(self->data->values[7],1,1); break;
    case 28: self->method(self->data->values[7],1,1); break;
    case 30: self->method(self->data->values[8],1,0); break;
    case 32: self->method(self->data->values[9],1,0); break;
    default: return;
    }
}
