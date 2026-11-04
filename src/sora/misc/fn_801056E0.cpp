#pragma force_active on
#pragma optimize high
#pragma fp_short on
#pragma strict_ieee_fp off
extern "C" {
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void setFrameVisible__8MuObjectFf(void*, float);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
extern void* g_sndSystem;
extern const unsigned long lbl_80409280[8];
extern float lbl_805A27C8;
}
struct Menu {
    char pad0[4];
    void* object;
    char pad8[4];
    void* message;
    char pad10[4];
    int selection;
    char pad18[0x2C];
    unsigned int input;
    char pad48[0x94];
    int result;
};
typedef void (*Handler)(Menu*);
extern "C" Handler lbl_8045D020[8];

extern "C" int fn_801056E0(Menu* self) {
    unsigned int input = self->input;
    int oldSelection = self->selection;
    int selection = oldSelection;
    if (input & 8) {
        selection = oldSelection - 1;
        if (selection < 0)
            selection = 7;
    }
    if (input & 4) {
        ++selection;
        if (selection >= 8)
            selection = 0;
    }
    if (selection != oldSelection) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        setFrameVisible__8MuObjectFf(self->object, lbl_805A27C8 + (float)selection);
        self->selection = selection;
        printIndex__5MuMsgFUlUlPv(self->message, 7, lbl_80409280[selection], 0);
    }
    lbl_8045D020[selection](self);
    return self->result;
}