#include <types.h>
#pragma force_active on

class Class_90698 {
public:
    virtual void fn_27_3608BC();
    virtual void fn_27_3608FC();
    virtual void fn_27_3609DC();
    virtual void fn_27_2D9348();
    virtual int fn_27_2D9344(u32);
    virtual void fn_27_2D9340();
    virtual void fn_27_2D933C();
    virtual void fn_27_2D9338();
    virtual void fn_27_2D9334();
    virtual void fn_27_2D932C();
    virtual void fn_27_2D9328();
    virtual void fn_27_2D9320(u32, u32, void*, void*, int, int, int, float, int);
    virtual void fn_27_2D931C();
    virtual void fn_27_2D9318();
    virtual void fn_27_2D9314();
    virtual void fn_27_2D9310();
    virtual void fn_27_2D930C();
    virtual void fn_27_2D9308();
};

struct A {
    char pad[0x64];
    Class_90698* obj64;
    char pad2[0x20];
    Class_90698* obj88;
};

struct Arg {
    char pad[0xd8];
    A* a;
};

extern "C" {
extern void* g_ftManager;
void* getOwner__9ftManagerFi(void*, int);
int fn_27_111E30(void*);
int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32, void*);
extern const float lbl_27_rodata_7A78;
extern const float lbl_27_rodata_7A7C;
}

extern "C" void fn_27_3608FC(void*, Arg* arg) {
    int id = arg->a->obj64->fn_27_2D9344(0x10000000);
    void* owner = getOwner__9ftManagerFi(g_ftManager, id);
    if (fn_27_111E30(owner) == 0) {
        float v[6];
        v[0] = lbl_27_rodata_7A78;
        v[1] = lbl_27_rodata_7A78;
        v[2] = lbl_27_rodata_7A78;
        v[3] = lbl_27_rodata_7A78;
        v[4] = lbl_27_rodata_7A78;
        v[5] = lbl_27_rodata_7A78;
        Class_90698* obj = arg->a->obj88;
        int ret = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(arg, 0x10000036, 0, arg->a);
        obj->fn_27_2D9320(0x011C0002, 0x11, &v[3], &v[0], 1, 0x10, ret, lbl_27_rodata_7A7C, -1);
    }
}