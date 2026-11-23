#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <it/item.h>
#pragma force_active on

extern "C" {
extern float lbl_41_rodata_EC8;

void* getInstance__9itManagerFv(void* self);
void* createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
    void* self, int kind, unsigned long arg, int team, void* res,
    unsigned char flag, int a, int b, int c);
void warp__8BaseItemFP5Vec3f(void* self, Vec3f* pos);
void fn_27_28F66C(void* self, float f);
}

struct NonPoly8 {
    int pad[2];
};

struct NonPoly60 {
    char pad[0x3C];
};

#define V(n) virtual void v##n();
#define V0_3 V(0) V(1) V(2) V(3)
#define V0_4 V0_3 V(4)
#define V0_7 V0_4 V(5) V(6) V(7)
#define V8_15 V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
#define V16_23 V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
#define V24_31 V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
#define V32_35 V(32) V(33) V(34) V(35)
#define V32_39 V32_35 V(36) V(37) V(38) V(39)
#define V40_42 V(40) V(41) V(42)
#define V40_47 V40_42 V(43) V(44) V(45) V(46) V(47)
#define V48_55 V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
#define V56_63 V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63)
#define V64_71 V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71)
#define V72_74 V(72) V(73) V(74)
#define V72_79 V72_74 V(75) V(76) V(77) V(78) V(79)
#define V80_86 V(80) V(81) V(82) V(83) V(84) V(85) V(86)

class VectorAPI : public NonPoly8 {
public:
    V0_7 V8_15 V16_23 V24_31 V32_35
    virtual Vec3f v36(int, bool);
};

class ItemAPI : public NonPoly60 {
public:
    V0_7 V8_15 V16_23 V24_31 V32_39 V40_42
    virtual void activate();
};

class Method6API {
public:
    V0_4
    virtual void set(int, int);
};

class Method88API {
public:
    V0_7 V8_15 V16_23 V24_31 V32_39 V40_47 V48_55
    V56_63 V64_71 V72_79 V80_86
    virtual void setPriority(int);
};

#define ACC (*(soModuleAccesser**)(self + 0x60))

inline soLinkModule& getLink(unsigned long id, char* self, unsigned long& out) {
    out = id;
    return ACC->getLinkModule();
}

extern "C" int fn_41_39A8C(char* self, int arg1, unsigned long arg2,
                           char* arg3, float farg0) {
    unsigned long taskId = 0;
    int team = *(int*)(*(char**)(self + 0xE4) + 0x28);
    void* manager =
        getInstance__9itManagerFv(*(char**)(self + 0xE4));
    char* item = (char*)createItem__9itManagerF6itKindUliP16soResourceModuleUciii(
        manager, arg1, arg2, team, 0, 0, 0xFFFF, 0, 0xFFFF);

    if (item != 0) {
        char* object = *(char**)(*(char**)(self + 0x1B4) + 4);
        Vec3f pos;
        Vec3f input;
        input.m_x = *(float*)(arg3 + 0x1C);
        input.m_y = *(float*)(arg3 + 0x20);
        input.m_z = *(float*)(arg3 + 0x24);
        Vec3f transformed =
            ((VectorAPI*)object)->v36(*(int*)(arg3 + 0x18), &input != 0);

        pos.m_x = transformed.m_x;
        double y = transformed.m_y;
        pos.m_z = transformed.m_z;
        pos.m_y = (float)y + lbl_41_rodata_EC8;
        warp__8BaseItemFP5Vec3f(item, &pos);
        fn_27_28F66C(item, farg0);
        ((ItemAPI*)item)->activate();

        char* module = *(char**)(*(char**)(self + 0x1B4) + 0x64);
        ((Method6API*)module)->set(*(int*)(item + 0x8BC), 0x1000000F);

        ((Method88API*)&ACC->getLinkModule())->setPriority(1);

        if (ACC->getLinkModule().isLink(4) == 1U) {
            ACC->getLinkModule().unlink(4);
        }

        if (getLink(((BaseItem*)item)->m_taskId, self, taskId).link(4, taskId) == 1U) {
            ACC->getLinkModule().setModelConstraintPosOrt(4, 0, 0, 1, true);
        }
        goto item_created;
    }
    return 0;

item_created:
    return 1;
}
