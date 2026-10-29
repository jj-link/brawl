#pragma force_active on
extern "C" int lbl_27_data_568E0;
extern "C" int lbl_27_data_568E4;
extern "C" void setVisibilityAttachedEffect__6GroundFUl(void*, unsigned long);

class AttachedEffect {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void* v12();
    int field;
};

struct grGimmick {
    unsigned char pad[0xFC];
    AttachedEffect* effects_a[10];
    AttachedEffect* effects_b[10];
};

extern "C" void setVisibilityAttachedEffect__9grGimmickFUl(grGimmick* self, unsigned long visible) {
    int found = 1;
    if (visible != 0) {
        for (int i = 0; i < 10; i++) {
            if (self->effects_a[i] != 0) {
                if (self->effects_a[i]->v12() != 0) {
                    AttachedEffect* other = self->effects_b[i];
                    if (other != 0) {
                        other->field = lbl_27_data_568E0;
                    }
                    self->effects_a[i]->v4();
                }
            }
        }
        setVisibilityAttachedEffect__6GroundFUl(self, 1);
        return;
    }
    if (visible == 0) {
        for (int i = 0; i < 10; i++) {
            if (self->effects_b[i] != 0) {
                if (self->effects_b[i]->v12() != 0) {
                    AttachedEffect* other = self->effects_a[i];
                    if (other != 0) {
                        other->field = lbl_27_data_568E4;
                    }
                    self->effects_b[i]->v4();
                    found = 0;
                }
            }
        }
        if (found != 0) {
            setVisibilityAttachedEffect__6GroundFUl(self, 0);
        }
    }
}
