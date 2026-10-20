#pragma force_active on
struct Entry {
    unsigned char pad[16];
    bool active;
    unsigned char tail[3];
};

extern "C" Entry lbl_10_data_610[5][2];
extern "C" void fn_800B330C(void*, void*, int);

struct Self {
    unsigned char pad[0x3CC];
    void* object;
};

extern "C" void fn_10_F9D4(Self* self, int index, bool flag) {
    lbl_10_data_610[index][!flag].active = true;
    fn_800B330C(self->object, &lbl_10_data_610[index][!flag], 0);
}
