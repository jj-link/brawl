#pragma force_active on
struct gfScene {
    void setLoadModule(const char*, bool);
};

extern const char lbl_1_data_6304[];
extern const char lbl_1_data_6320[];

extern "C" void fn_1_1E628(gfScene* self) {
    self->setLoadModule(lbl_1_data_6304, false);
    self->setLoadModule(lbl_1_data_6320, false);
}
