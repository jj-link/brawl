#include <so/so_module_accesser.h>
#pragma force_active on
struct FalcoData { Vec3f position; float scale; };
class Object_vptr_0 {
public:
    virtual void fn_108_8008();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(FalcoData*);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual unsigned int slot14();
    virtual void slot15();
    virtual void slot16();
};
extern "C" {
extern void* lbl_27_bss_F0;
void fn_27_12E7C8(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_108_A1C8(Vec3f*, const Vec3f*);
}
extern "C" void fn_108_A064(void* self) {
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
                FalcoData data;
                Vec3f pos = (*(soModuleAccesser**)(s + 0x60))->getPostureModule().getPos();
                fn_108_A1C8(&data.position, &pos);
                data.scale = (*(soModuleAccesser**)(s + 0x60))->getPostureModule().getRot(0).m_x;
                if ((*(Object_vptr_0**)(s + 0x1d094))->slot14() == 1)
                    (*(Object_vptr_0**)(s + 0x1d094))->slot7();
                (*(Object_vptr_0**)(s + 0x1d094))->slot9(&data);
            }
        }
    }
}