#pragma force_active on
extern "C" {

struct sora_melee_unk {
    int field_0;
    int field_4;
    unsigned int b0 : 6;
    unsigned int b1 : 1;
};

int fn_27_CD860(const sora_melee_unk* self) {
    return self->b1;
}

}
