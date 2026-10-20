#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct ViewerData {
    u8 pad0[0x1B50];
    u32 input;
    u8 pad1B54[0x1BFC - 0x1B54];
    u32 state;
    u32 previousState;
    u8 pad1C04[0x1C64 - 0x1C04];
    u8 flags;
};

struct ViewerBase {
    u8 pad0[0x3C];
};

struct ViewerInterface : ViewerBase {
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
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void changeState(int, int);
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void update(int, int);
};

struct Viewer : ViewerInterface {
    u8 pad40[0x1A8 - 0x40];
    u32 flags;
    ViewerData* data;
};

extern "C" {
extern void* g_sndSystem;
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

void fn_6_7C90(Viewer* self) {
    if (self->flags & 2) {
        if ((self->data->flags >> 7) & 1) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 3, -1, 0, 0, -1);
        } else {
            self->data->state = 0x23;
            self->changeState(10, 1);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
        }
    } else if ((self->data->input & 8) || (self->flags & 4)) {
        self->data->previousState = self->data->state;
        self->data->state = 0;
        self->changeState(1, 1);
        playSE__9sndSystemF5SndIDiiii(
            g_sndSystem, (self->flags & 4) ? 2 : 0, -1, 0, 0, -1);
    } else if (self->data->input & 1) {
        self->data->state = 30;
        self->changeState(8, 1);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
    } else {
        self->update(0, 5);
    }
}
}
