#pragma force_active on
struct FighterObj {
    char pad[0x4c];
    void* model;
};

extern "C" {
void fn_800B3C5C(void* model, const void* info, int flag);
extern const unsigned char lbl_27_data_994C0[0x28];

void fn_27_38A164(FighterObj* self, int index) {
    fn_800B3C5C(self->model, &lbl_27_data_994C0[index * 20], 1);
}
}
