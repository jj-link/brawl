#pragma force_active on

struct Entry { char pad[0xA]; short val; };

struct Class_19FD0_base { char pad[0x10]; };
class Class_19FD0 {
public:
    virtual void fn_27_DCA5C();
    virtual void fn_27_DC3F0();
    virtual Entry* fn_27_DC400(int);
    virtual void fn_27_D32CC();
    virtual void fn_27_86AD0();
    virtual void fn_27_D320C();
    virtual void fn_27_DC504();
    virtual void fn_27_DC6B4();
    virtual void fn_27_DCA14();
    virtual void fn_27_DC410();
    virtual void fn_27_DC5C0();
    virtual void fn_27_DC770(int, int*);
    virtual void fn_27_DC888();
    virtual void fn_27_D32C4();
    virtual unsigned int fn_27_D32B8();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
    virtual void slot5();
    virtual unsigned int slot6(int);
    char pad[0xC];
    Class_19FD0 inner;
    char pad2[0xE0];
    unsigned char flag;

    inline int find(int limit) {
        if (limit <= -1) return slot4();
        int n = slot4();
        for (int i = 0; i < n; i++) {
            int value = inner.fn_27_DC400(i)->val;
            if (value <= -1) return i;
            if (value > limit) return i;
        }
        return n;
    }
};

extern "C" int fn_27_1BE7F0(soNullable*);
extern "C" void fn_27_FE124(int*, int, int, short*, int);

extern "C" int fn_27_1BDFE8(soNullable* self, int id, int slot, short* half, int limit)
{
    if (self->inner.fn_27_D32B8() == 1U) return -1;
    if (self->flag == 0 || slot > -1) {
        if (self->slot6(slot) == 1U) return -1;
    }
    if (self->flag == 0 && slot <= -1) {
        slot = fn_27_1BE7F0(self);
        if (slot <= -1) return -1;
    }
    int idx = self->find(limit);
    if (idx < 0) return -1;
    short s = *half;
    int out[3];
    fn_27_FE124(out, id, slot, &s, limit);
    self->inner.fn_27_DC770(idx, out);
    return slot;
}
