#pragma force_active on

struct Some {
    char pad[4];
    int unk4;
    char pad2[1];
    unsigned char unk9;
};

struct Result {
    unsigned char b7 : 1;
    unsigned char rest : 7;
    char pad[3];
    Some* unk4;
    int unk8;
    unsigned char unkC;
};

class Class_7948 {
public:
    virtual void fn_27_689B0();
    virtual Result* fn_27_68A80(int id);
};

struct Self {
    char pad[0x14];
    Class_7948* obj;
    int unk18;
};

extern "C" void fn_27_68D04(Self* self) {
    if (self->unk18 != -1) {
        Result* r = self->obj->fn_27_68A80(self->unk18);
        if (r->unk4->unk9 != 0 && r->unk8 > 0) {
            unsigned char c = r->unkC + 1;
            r->unkC = c;
            if (c >= r->unk4->unk4) {
                r->unkC = 0;
            }
            if (--r->unk8 == 0) {
                r->b7 = 0;
            }
        }
        Result* r2 = self->obj->fn_27_68A80(self->unk18);
        if (!r2->b7) {
            self->unk18 = -1;
        }
    }
}
