#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_7618;
extern const f32 lbl_27_rodata_761C;

struct TempFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
};

class Temp {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32);
};

class StatusModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Temp* v6(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int, void*);
};

class Module88 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(u32 a, int b, void* c, void* d, int e, int f, int g, s32 h, f32 weight);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22(u32 a, int b, int c, void* d);
};

extern "C" void fn_27_32DE90(void* unused, u8* fighter, int arg) {
    u8* mods = *(u8**)(fighter + 0xd8);
    Work* work = *(Work**)(mods + 0x64);
    StatusModule* status = *(StatusModule**)(mods + 0x7c);

    status->v21(2, fighter);
    Temp* temp = status->v6(2);
    temp->v6();
    ((TempFlags*)temp)->flag = 0;

    if (arg == 1) {
        u32 value = work->v4(0x20000000);
        u8* mods2 = *(u8**)(fighter + 0xd8);
        Module88* m88 = *(Module88**)(mods2 + 0x88);
        m88->v22(value, 1, 1, mods2);
        Module88* m88again = *(Module88**)(*(u8**)(fighter + 0xd8) + 0x88);
        float colors[6] = {
            lbl_27_rodata_761C, lbl_27_rodata_761C, lbl_27_rodata_761C,
            lbl_27_rodata_761C, lbl_27_rodata_761C, lbl_27_rodata_761C,
        };
        m88again->v11(0xB000A, 0, &colors[3], &colors[0], 0, 0, 0, -1, (lbl_27_rodata_7618));
    }
}
