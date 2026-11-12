#pragma force_active on
// Best result so far: 99.8-99.9% (2 lines differ). The block-C reload of self->a
// lands in r31 here; the original keeps it in r30 across the getInstance() call.
struct Self {
    int unk0;
    short a;
    short b;
    short c;
};

class Class_1640 {
public:
    virtual void fn_47_7394();
    virtual void fn_47_685C();
    virtual void fn_47_686C();
    virtual void fn_47_4D54();
    virtual void fn_47_499C();
    virtual void fn_47_4024();
    virtual bool fn_47_6B60(int id);
    virtual void fn_47_6C1C();
    virtual void fn_47_734C();
};

class Class_18E8 {
public:
    virtual void fn_47_8D88();
    virtual void fn_47_81A8();
    virtual bool fn_47_81B8(short id);
    virtual void fn_47_4EB4(short id, short sendId);
    virtual bool fn_47_4968(short id);
    virtual void fn_47_41B0();
    virtual void fn_47_84E4();
    virtual void fn_47_85A0();
    virtual void* fn_47_8D40(short id);
};

class Class_Dc {
public:
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual short fn_dc20(Self* self, signed char p);
};

extern "C" {
Class_1640* getInstance__13soEventSystemFv();
Class_18E8* getManager__13soEventSystemFl(Class_1640*, long);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_47_data_1398[];
extern char lbl_47_data_1080[];

void fn_47_3618(Self* self, int arg1, signed char arg2) {
    unsigned int r31 = 0;
    Class_18E8* m;
    int r30 = 0;
    int a2;
    int r4 = 0;
    int r5 = 0;
    int a = self->a;
    if (a >= 0 && self->b >= 0) {
        r5 = 1;
    }
    if (r5 != 0 && self->c > -1) {
        r4 = 1;
    }
    if (r4 != 0) {
        if (getInstance__13soEventSystemFv()->fn_47_6B60(a) == 1) {
            r30 = 1;
        }
    }
    if (r30 != 0) {
        if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->fn_47_4968(self->b) == 1) {
            r31 = 1;
        }
    }
    if (r31 == 1) {
        a2 = self->a;
        Class_1640* inst = getInstance__13soEventSystemFv();
        if (inst->fn_47_6B60(a2) == 1) {
            getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->fn_47_4EB4(self->b, self->c);
        }
        self->c = -1;
        self->a = -1;
    }
    if (arg1 > -1 && self->b > -1) {
        if (getInstance__13soEventSystemFv()->fn_47_6B60(arg1) != 0) {
            if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), arg1)->fn_47_81B8(self->b) != 1) {
                m = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), arg1);
                short ret;
                if (m->fn_47_4968(self->b) == 0) {
                    ret = -1;
                } else {
                    Class_Dc* dc = (Class_Dc*)__dynamic_cast(m->fn_47_8D40(self->b), 0, lbl_47_data_1398, lbl_47_data_1080, 0);
                    if (dc == 0) {
                        ret = -1;
                    } else {
                        ret = dc->fn_dc20(self, arg2);
                    }
                }
                self->c = ret;
                if (ret > -1 && ret > -1) {
                    self->a = arg1;
                }
            }
        }
    }
}
}
