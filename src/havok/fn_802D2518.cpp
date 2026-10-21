#pragma force_active on
extern "C" {
extern int fn_802D1680(void);
extern void fn_802D1588(void* arg0);
extern void fn_802D15A8(void* self);
extern char lbl_80410618[];
extern struct {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
} lbl_80532790;

void fn_802D2518(void) {
    int temp_r3;

    temp_r3 = fn_802D1680();
    lbl_80532790.unk0 = (void*)(lbl_80410618 + 0x21);
    lbl_80532790.unk4 = (void*)fn_802D1588;
    lbl_80532790.unk8 = (void*)fn_802D15A8;
    lbl_80532790.unkC = (void*)temp_r3;
}
}

__declspec(section ".ctors") extern void* const fn_802D2518_ctor = (void*)fn_802D2518;
