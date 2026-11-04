#pragma force_active on

extern "C" {
extern const float lbl_14_rodata_0;
extern const float lbl_14_rodata_200;
void setFrameNode__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
unsigned long strlen(const char*);
}

struct Menu {
    char pad0[0xB8];
    void* object;
    void* other;
    char pad1[0x2438];
    int state;
    int mode;
    char text[1];
};

extern "C" void fn_14_3A7C(Menu* self, int mode) {
    float frame = mode;
    void* object = self->object;
    setFrameNode__8MuObjectFf(object, frame);
    setFrameVisible__8MuObjectFf(object, frame);
    float visible;
    if (strlen(self->text) >= 12) {
        visible = lbl_14_rodata_200;
    } else {
        visible = lbl_14_rodata_0;
    }
    setFrameVisible__8MuObjectFf(self->other, visible);
    self->mode = mode;
    self->state = 0;
}
