#include <so/so_module_accesser.h>
#pragma force_active on

struct WolfData { Vec3f position; float scale; };
class Class_78E0 {
public:
    virtual void fn_125_8060();
    virtual void fn_125_1057C();
    virtual void fn_125_10A38();
    virtual void fn_125_10A34();
    virtual void fn_125_10A30();
    virtual void fn_125_10A2C();
    virtual void fn_125_10A24();
    virtual void fn_125_10A6C();
    virtual void fn_125_10A64();
    virtual void fn_125_10A5C(WolfData*);
    virtual void fn_125_10A54();
    virtual void fn_125_10A4C();
    virtual void fn_125_109E4();
    virtual void fn_125_10A18();
    virtual unsigned int fn_125_10A0C();
    virtual void fn_125_10A04();
    virtual void fn_125_109F8();
};
class Class_7A60 {
public:
    virtual void fn_125_8060();
    virtual void fn_125_10520();
    virtual void fn_125_10BFC();
    virtual void fn_125_10BF4();
    virtual void fn_125_10BEC();
    virtual void fn_125_10BE4();
    virtual void fn_125_10BDC();
    virtual void fn_125_10BD4();
    virtual void fn_125_10BCC();
    virtual void fn_125_10BC4(WolfData*);
    virtual void fn_125_10BBC();
    virtual void fn_125_10BB4();
    virtual void fn_125_10BAC();
    virtual void fn_125_10BA4();
    virtual unsigned int fn_125_10B54();
    virtual void fn_125_10B9C();
    virtual void fn_125_10B8C();
};
extern "C" {
extern void* lbl_27_bss_F0;
void fn_27_12E7C8(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_125_A220(Vec3f*, const Vec3f*);
}
extern "C" void fn_125_A0BC(void* self) {
    fn_27_12E7C8(self);
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (p) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        unsigned char* s = (unsigned char*)self;
        if (!(*(soModuleAccesser**)(s + 0x60))->getStopModule().isStop()) {
            if ((*(soModuleAccesser**)(s + 0x60))->getStatusModule().getStatusKind() == 0x113) {
                WolfData data;
                Vec3f pos = (*(soModuleAccesser**)(s + 0x60))->getPostureModule().getPos();
                fn_125_A220(&data.position, &pos);
                data.scale = (*(soModuleAccesser**)(s + 0x60))->getPostureModule().getRot(0).m_x;
                if ((*(Class_78E0**)(s + 0x1cc8c))->fn_125_10A0C() == 1)
                    (*(Class_78E0**)(s + 0x1cc8c))->fn_125_10A6C();
                (*(Class_78E0**)(s + 0x1cc8c))->fn_125_10A5C(&data);
            }
        }
    }
}