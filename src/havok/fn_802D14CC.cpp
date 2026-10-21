#pragma force_active on
extern "C" {
int fn_802D0B94(void);
void fn_802D0A94(void* arg0);
void fn_802D0AC0(void* obj);
extern char lbl_80410580[];
extern unsigned int lbl_80532758[4];

void fn_802D14CC(void) {
    unsigned int r;
    r = fn_802D0B94();
    lbl_80532758[0] = (unsigned int)lbl_80410580 + 0x25;
    lbl_80532758[1] = (unsigned int)fn_802D0A94;
    lbl_80532758[2] = (unsigned int)fn_802D0AC0;
    lbl_80532758[3] = r;
}
}

__declspec(section ".ctors") extern void* const fn_802D14CC_ctor = (void*)fn_802D14CC;
