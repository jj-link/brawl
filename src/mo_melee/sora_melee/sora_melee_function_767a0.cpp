#pragma force_active on
class Inner {
public:
    virtual void slot0();
    virtual unsigned char* getFlags(int index);
    virtual void slot2();
    virtual int getCount();
};

struct Owner {
    int unk0;
    Inner* inner;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

extern "C" {

unsigned int fn_27_AB2F4(unsigned char* elem, int a, int b, int* out1, int* out2, int c, int d);

int fn_27_767A0(Owner* self, int a, int b, int index, int c, int d) {
    if (index != -1) {
        unsigned char* flags = self->inner->getFlags(index);
        if (!((flags[0] >> 7) & 1)) {
            return 0;
        }
        int o1 = -1;
        int o2 = 0;
        if (fn_27_AB2F4(flags, a, b, &o1, &o2, c, d) == 1) {
            int r1 = o1;
            int r2 = o2;
            self->unkC = index;
            self->unk10 = r1;
            self->unk14 = r2;
            return 1;
        }
        return 0;
    }

    int count = self->inner->getCount();
    for (int i = 0; i < count; i++) {
        unsigned char* flags = self->inner->getFlags(i);
        if ((flags[0] >> 7) & 1) {
            int o1 = -1;
            int o2 = 0;
            if (fn_27_AB2F4(flags, a, b, &o1, &o2, c, d) == 1) {
                int r1 = o1;
                int r2 = o2;
                self->unkC = i;
                self->unk10 = r1;
                self->unk14 = r2;
                return 1;
            }
        }
    }
    return 0;
}

}
