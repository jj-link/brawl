#pragma force_active on
typedef unsigned int u32;

struct MenuResult {
    unsigned char data[0x44];
};

struct ViewerBase {
    unsigned char pad[0x3C];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual MenuResult getResult();
};

struct Manager {
    unsigned char pad[0x350];
    int state;
};

struct ViewerData {
    unsigned char pad0[0x1A0];
    u32 id;
    unsigned char pad1[0x1BF4 - 0x1A4];
    int state;
    unsigned char pad2[4];
    int nextState;
    unsigned char pad3[0x1CE4 - 0x1C00];
    Manager* manager;
};

struct Viewer : ViewerBase {
    unsigned char pad1[0x1AC - 0x40];
    ViewerData* data;
};

extern "C" {
extern void* g_gfHomeMenu;
extern unsigned char g_gfShutdownManager[];

int setBan__10gfHomeMenuFUlUl(void*, u32, u32);
void fn_800C7150(Manager*, u32, const MenuResult&);
void fn_800C71EC(Manager*, u32, const MenuResult&);

void fn_6_72B8(Viewer* self, int flag) {
    if (setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 1, 5) &&
        self->data->manager->state == 0) {
        g_gfShutdownManager[0xD] = 0;
        if (flag) {
            ViewerData* data = self->data;
            fn_800C7150(data->manager, data->id, self->getResult());
            self->data->nextState = 12;
        } else {
            ViewerData* data = self->data;
            fn_800C71EC(data->manager, data->id, self->getResult());
            self->data->nextState = 15;
        }
        self->data->state = 4;
    }
}
}
