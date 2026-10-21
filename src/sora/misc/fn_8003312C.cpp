#pragma force_active on
struct S {
    int unk0;
    void* unk4;
    unsigned char unk8;
};

extern char lbl_804230C8[];
extern char lbl_804230FC[];
extern struct S lbl_804953A0;

extern "C" {
void fn_8003312C(void) {
    lbl_804953A0.unk4 = lbl_804230FC;
    lbl_804953A0.unk0 = 0;
    lbl_804953A0.unk4 = lbl_804230C8;
    lbl_804953A0.unk8 = 1;
}
}

__declspec(section ".ctors") extern void* const fn_8003312C_ctor = (void*)fn_8003312C;
