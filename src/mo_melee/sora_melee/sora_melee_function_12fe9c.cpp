#include <types.h>
#include <sr/sr_common.h>
#include <cm/cm_camera_controller.h>

#include <mt/mt_vector.h>
#pragma force_active on
struct Info { int id; Vec3f pos; float size; };
#define V(n) virtual void slot##n();
class Object_vptr_0 {
public:
V(0) V(1) V(2)
virtual int slot3();
virtual int slot4(int);
V(5) V(6) V(7) V(8)
virtual unsigned int slot9();
V(10) V(11) V(12) V(13) V(14) V(15) V(16)
virtual unsigned int slot17(int);
V(18) V(19) V(20) V(21)
virtual float slot22();
V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30)
virtual int slot31(int);
V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42)
virtual unsigned int slot43(int);
V(44) V(45)
virtual Info* slot46(int);
};
struct Prefix8 { char pad[8]; };
class Model : public Prefix8 {
public:
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
virtual Vec3f slot37(int, Vec3f*, int, int);
V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61)
virtual unsigned char slot62();
};
struct Prefix60 { char pad[0x3c]; };
class Self : public Prefix60 {
public:
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119) V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129) V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138) V(139) V(140) V(141) V(142) V(143) V(144) V(145) V(146) V(147) V(148) V(149) V(150) V(151) V(152) V(153) V(154) V(155) V(156) V(157)
virtual void slot158(int);
virtual int slot159();
V(160) V(161) V(162) V(163) V(164) V(165) V(166)
virtual void slot167(int);
virtual void slot168(int);
virtual void slot169(int);
virtual void slot170(int);
};
#undef V
extern "C" {
void fn_27_5F38(void*);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
void fn_80025940(unsigned int, const float*, float);
extern void* g_ftManager;
extern void* lbl_27_bss_F0;
extern u8 lbl_27_data_292A0;
extern const float lbl_27_rodata_1070;
}
#define MOD(a) (*reinterpret_cast<u8**>((a) + 0xd8))
#define OBJ(a, off) (*reinterpret_cast<Object_vptr_0**>(MOD(a) + (off)))
#define MODEL(a) (*reinterpret_cast<Model**>(MOD(a) + 4))
extern "C" void fn_27_12FE9C(Self* self) {
    u8 kind;
    u8* accesser = *reinterpret_cast<u8**>(reinterpret_cast<u8*>(self) + 0x60);
    fn_27_5F38(self);
    if (OBJ(accesser, 0x14)->slot3() != 5) {
        if (OBJ(accesser, 0x60)->slot43(0) == 1) {
            self->slot169(0);
            if (OBJ(accesser, 0x64)->slot17(0x1200001b) == 1 &&
                OBJ(accesser, 0x64)->slot4(0x10000020) <= 0) {
                self->slot167(1);
            } else {
                self->slot167(0);
            }
            if (OBJ(accesser, 0x64)->slot17(0x1200001c) == 1) {
                self->slot168(1);
            } else {
                self->slot168(0);
            }
        } else {
            kind = MODEL(accesser)->slot62();
            if (OBJ(accesser, 0x14)->slot3() != 5 &&
                ((OBJ(accesser, 0x64)->slot17(0x12000019) == 1 &&
                  OBJ(accesser, 0x58)->slot9() == 1) ||
                 OBJ(accesser, 0x64)->slot17(0x1200003a) == 1) &&
                kind != lbl_27_data_292A0) {
                self->slot169(1);
                Info* info = OBJ(accesser, 0x60)->slot46(0);
                Vec3f pos(info->pos.m_x, info->pos.m_y, info->pos.m_z);
                const Vec3f& result = MODEL(accesser)->slot37(info->id, &pos, 0, 0);
                float scale = OBJ(accesser, 0x0c)->slot22();
                fn_80025940(kind, &result.m_x, lbl_27_rodata_1070 * (info->size * scale));
            } else {
                self->slot169(0);
            }
            self->slot167(0);
            self->slot168(0);
        }
        if (CameraController::getInstance()->m_currentControllerKind != CameraController::Tech) {
            if (OBJ(accesser, 0x60)->slot43(1) == 1) {
                self->slot170(0);
            } else if (
                OBJ(accesser, 0x14)->slot3() != 5 &&
                OBJ(accesser, 0x64)->slot17(0x1200001a) == 1 &&
                OBJ(accesser, 0x64)->slot17(0x12000007) == 0 &&
                OBJ(accesser, 0x64)->slot17(0x12000018) == 0 &&
                OBJ(accesser, 0x20)->slot31(0) <= 0) {
                self->slot170(1);
            } else {
                self->slot170(0);
            }
        }
    } else {
        self->slot167(0);
        self->slot168(0);
        self->slot169(0);
        self->slot170(0);
    }
    if (lbl_27_bss_F0 == 0) {
        void* p = operator new(0x4c, Heaps::System);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1 &&
        !(*reinterpret_cast<u8*>(static_cast<u8*>(g_ftManager) + 0x6e) & 1)) {
        int idx = self->slot159();
        if (idx != -1) {
            self->slot158(idx);
        }
    }
}
