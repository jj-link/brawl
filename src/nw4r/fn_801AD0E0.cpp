#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int, void*);
};

struct Table {
    int unk0;
    Object_vptr_0** unk4;
    Object_vptr_0** unk8;
    unsigned int unkC;
    unsigned int unk10;
    unsigned int unk14;
};

extern int lbl_805A0558;

extern "C" int fn_801AB164(Object_vptr_0* obj, int a, void* out);
extern "C" int fn_8016372C(int a, void* b);

extern "C" int fn_801AD0E0(Table* arg0, Object_vptr_0* arg1, int arg2, int arg3) {
    int result = 0;
    int sp8;
    int sp10[4];

    if (lbl_805A0558 != 0) {
        arg1->slot7(9, &sp8);
        if (sp8 != 0) {
            fn_801AB164(arg1, 1, &sp10[0]);
            int r = fn_8016372C(lbl_805A0558, &sp10[0]);
            if (r == 0) {
                return 2;
            }
            if (r == 1) {
                result = 1;
            }
        }
    }

    if (arg2 != 0) {
        unsigned int n = arg0->unk10;
        if (n < arg0->unkC) {
            arg0->unk4[arg0->unk10++] = arg1;
        } else {
            return result;
        }
    }

    if (arg3 != 0) {
        unsigned int m = arg0->unk14;
        if (m < arg0->unkC) {
            arg0->unk8[arg0->unk14++] = arg1;
        } else {
            return result;
        }
    }

    return result;
}
