#pragma force_active on
extern char lbl_80529994[];

typedef void (*FnPtr)(int, int);

void fn_80234A90(void) {
    FnPtr f = *(FnPtr*)(lbl_80529994 + 0x50);
    f(1, 0);
}
