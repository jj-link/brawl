#pragma force_active on
extern "C" {

struct unk_27 {
    int unk0;
    int unk4;
    int unk8;
};

int fn_27_1A50DC(struct unk_27 *p) {
    return p->unk8 >> 27;
}

}
