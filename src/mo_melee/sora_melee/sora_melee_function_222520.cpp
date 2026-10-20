#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
extern float lbl_27_data_547E0;
extern unsigned char lbl_27_data_547E4;
float fn_8004E94C(void*);
int fn_8004E958(void*);
}

class Stage {
public:
    unsigned char pad[0x40];
    int state;
    void processEnd();
};

void Stage::processEnd() {
    if (state == 4) {
        lbl_27_data_547E0 = fn_8004E94C(g_GameGlobal);
        lbl_27_data_547E4 = fn_8004E958(g_GameGlobal);
    }
}
