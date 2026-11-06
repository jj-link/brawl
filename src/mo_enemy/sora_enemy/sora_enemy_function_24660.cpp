#pragma force_active on

extern "C" float lbl_41_rodata_D54;
extern "C" float lbl_41_rodata_D60;

class VirtFloat {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual float vf9();
};

struct Inner {
    char pad[0xc];
    VirtFloat* virt;
};

struct Self {
    char pad[0xd8];
    Inner* inner;
};

extern "C" int fn_41_24660(Self* self, int arg1, int arg2) {
    if (arg2 == 0) {
        if (arg1 == arg2) return 1;
    } else if (arg2 == 1) {
        if (arg1 == arg2) return 1;
    } else if (arg2 == 2) {
        VirtFloat* obj = self->inner->virt;
        float val = obj->vf9();
        if (lbl_41_rodata_D54 == val) {
            if (arg1 == 0) return 1;
        } else if (lbl_41_rodata_D60 == val) {
            if (arg1 == 1) return 1;
        } else {
            return 0;
        }
    } else if (arg2 == 3) {
        VirtFloat* obj = self->inner->virt;
        float val = obj->vf9();
        if (lbl_41_rodata_D54 == val) {
            if (arg1 == 1) return 1;
        } else if (lbl_41_rodata_D60 == val) {
            if (arg1 == 0) return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 0;
}