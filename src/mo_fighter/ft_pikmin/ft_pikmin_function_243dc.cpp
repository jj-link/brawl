#pragma force_active on

class wnPikminPikmin {
public:
    char pad_00[0x28];
    unsigned int m_28;
};

class PikminListIface {
public:
    virtual void vf0();
    virtual wnPikminPikmin** vf1(int);
    virtual void vf2();
    virtual int vf3();
    virtual unsigned int vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(void*);
    virtual void vf11();
    virtual void vf12(int);
};

struct Fn113Owner : PikminListIface {
    char pad_04[0x80 - sizeof(PikminListIface)];
    PikminListIface m_list80;
};

extern "C" unsigned int fn_113_18168(void* p);
extern "C" void fn_113_25530(Fn113Owner* self);

extern "C" void fn_113_243DC(Fn113Owner* self, int count) {
    if (self->vf4() == 1) {
        return;
    }
    int i = 0;
    int j = 0;
    while (j < count) {
        if (i >= self->vf3() || self->vf4() == 1) {
            return;
        }
        if (fn_113_18168(*self->vf1(i)) == 1) {
            self->m_list80.vf10(self->vf1(i));
            self->vf12(i);
        } else {
            i++;
        }
        j++;
    }
    fn_113_25530(self);
}
