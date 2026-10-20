#pragma force_active on
extern "C" {
extern char lbl_27_data_36B70[];
}

struct fn_27_S {
    void* unk0;
    void* unk4;
    unsigned int unk8;
};

extern "C" void fn_27_1A30FC(void* self) {
    fn_27_S* s = (fn_27_S*)self;
    unsigned int v = s->unk8;
    char* base = lbl_27_data_36B70;
    s->unk0 = base;
    s->unk4 = base + 0x48;
    s->unk8 = v & 0x1FFF;
}
