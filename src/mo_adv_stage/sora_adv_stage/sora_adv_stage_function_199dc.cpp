#pragma force_active on
class Sub {
public:
    virtual void vf0();
    virtual void vf1(float f);
};

class Ground {
public:
    void renderPre();
    char pad[0x150];
    Sub* m_subs[4];
};

extern float lbl_27_data_547E0;

extern "C" void fn_40_199DC(Ground* self) {
    self->renderPre();
    float f = lbl_27_data_547E0;
    for (unsigned int i = 0; i < 4; i++) {
        Sub* s = self->m_subs[i];
        if (s) {
            s->vf1(f);
        }
    }
}
