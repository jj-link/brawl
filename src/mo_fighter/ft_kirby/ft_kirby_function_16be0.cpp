#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Fn96Kinetic {
public:
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(int, Vec2f*, Vec3f*, soModuleAccesser*);
    virtual void* vfn7(int);
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual s32 vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual float vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27(int);
};

struct Fn96Enable {
    unsigned char enabled : 1;
};

extern "C" {
extern const char lbl_96_data_B2F4[], lbl_96_data_5E00[];
extern const char lbl_96_rodata_88[];
extern const float lbl_96_rodata_94;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_96_17058(int, soModuleAccesser*);
void fn_27_89DAC(int, soModuleAccesser*);
void fn_27_1652A8(soModuleAccesser*, u32, u32, float, float, u32, u32);
void fn_27_164BF0(soModuleAccesser*, const void*, u32, float, u32);
}

extern "C" void fn_96_16BE0(s32 arg0, soModuleAccesser* accesser) {
    s32 state = (*(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0x70))->vfn17();
    switch (state) {
    case 0x11B:
    case 0x121:
        (*(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0x20))->vfn27(0);
        return;
    case 0x11C: {
        Fn96Kinetic* m7 = *(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
        Fn96Kinetic* energy = static_cast<Fn96Kinetic*>(__dynamic_cast(m7->vfn7(1), 0, lbl_96_data_B2F4, lbl_96_data_5E00, 1));
        Vec2f v(lbl_96_rodata_94, lbl_96_rodata_94);
        v.m_y = soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
        Vec3f rot;
        energy->vfn6(0, &v, fn_96_BC54(&rot, lbl_96_rodata_94, lbl_96_rodata_94, lbl_96_rodata_94), accesser);
        reinterpret_cast<Fn96Enable*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
        return;
    }
    case 0x124:
    case 0x125:
        (*(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0xc))->vfn12();
        (*(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0x7c))->vfn10();
        return;
    case 0x11E: {
        float temp = (*(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0xc))->vfn23();
        float k = soValueAccesser::getConstantFloat(accesser, 0xfa2, 0);
        float f31 = k * temp;
        fn_27_1652A8(accesser, 0x1e5, 0x21000004, soValueAccesser::getConstantFloat(accesser, 0xbbb, 0), f31, 0x21000005, 0);
        fn_27_164BF0(accesser, lbl_96_rodata_88, 0x21000004, f31, 0x21000005);
        return;
    }
    case 0x120:
        fn_96_17058(arg0, accesser);
        fn_27_89DAC(3, accesser);
        return;
    case 0x122: {
        Fn96Kinetic* m7 = *(Fn96Kinetic**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
        Fn96Kinetic* energy = static_cast<Fn96Kinetic*>(__dynamic_cast(m7->vfn7(1), 0, lbl_96_data_B2F4, lbl_96_data_5E00, 1));
        Vec2f v(lbl_96_rodata_94, lbl_96_rodata_94);
        v.m_y = -soValueAccesser::getConstantFloat(accesser, 0xfa4, 0);
        Vec3f rot;
        energy->vfn6(0, &v, fn_96_BC54(&rot, lbl_96_rodata_94, lbl_96_rodata_94, lbl_96_rodata_94), accesser);
        reinterpret_cast<Fn96Enable*>(reinterpret_cast<unsigned char*>(energy) + 5)->enabled = 1;
        return;
    }
    default:
        return;
    }
}
