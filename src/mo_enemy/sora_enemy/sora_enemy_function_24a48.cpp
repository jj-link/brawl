#pragma force_active on
extern "C" float lbl_41_rodata_D54;
extern "C" float lbl_41_rodata_D60;
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual float fn_41_12784();
};
struct Inner { char pad[0xc]; soAnimCmdEventObserver* virt; };
struct Self { char pad[0xd8]; Inner* inner; };
extern "C" int fn_41_24A48(Self* self, int arg1, int arg2) {
    if (arg2 == 0) {
        if (arg1 == arg2) return 1;
    } else if (arg2 == 1) {
        if (arg1 == arg2) return 1;
    } else if (arg2 == 2) {
        if (arg1 == arg2) return 1;
    } else if (arg2 == 3) {
        if (arg1 == arg2) return 1;
    } else if (arg2 == 4) {
        soAnimCmdEventObserver* obj = self->inner->virt;
        float val = obj->fn_41_12784();
        if (lbl_41_rodata_D54 == val) {
            if (arg1 == 2) return 1;
        } else if (lbl_41_rodata_D60 == val) {
            if (arg1 == 3) return 1;
        } else {
            return 0;
        }
    } else if (arg2 == 5) {
        soAnimCmdEventObserver* obj = self->inner->virt;
        float val = obj->fn_41_12784();
        if (lbl_41_rodata_D54 == val) {
            if (arg1 == 3) return 1;
        } else if (lbl_41_rodata_D60 == val) {
            if (arg1 == 2) return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 0;
}