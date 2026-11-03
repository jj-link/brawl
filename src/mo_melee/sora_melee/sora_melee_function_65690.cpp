#pragma force_active on
extern "C" {
extern float lbl_27_rodata_8FC;
extern char lbl_27_data_7438[];
void* fn_27_8CDD4(void*);
void* fn_27_8CDF4(void*);
}

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Hdr8 {
    int a;
    int b;
};

class Obj8 : public Hdr8 {
public:
    virtual void slot0();
    virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
    virtual void slot17(unsigned int, float);
    virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31();
    virtual void* slot32(char*);
    virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual Vec3 slot36(void*, unsigned int);
};

class IfaceY {
public:
    virtual void isNull();
    virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(unsigned int);
    virtual unsigned int slot9(unsigned int);
    virtual unsigned int slot10(unsigned int);
    virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(unsigned int, void*, unsigned int);
    virtual void slot17();
    virtual void* slot18(unsigned int);
    virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28();
    virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33();
    virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38();
    virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void slot48();
    virtual void slot49(); virtual void slot50(); virtual void slot51(); virtual void slot52(); virtual void slot53();
    virtual void slot54(); virtual void slot55(); virtual void slot56(); virtual void slot57(); virtual void slot58();
    virtual void slot59(); virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67(); virtual void slot68();
    virtual void slot69(); virtual void slot70(); virtual void slot71(); virtual void slot72(); virtual void slot73();
    virtual void slot74(); virtual void slot75(); virtual void slot76(); virtual void slot77(); virtual void slot78();
    virtual void slot79(); virtual void slot80(); virtual void slot81(); virtual void slot82(); virtual void slot83();
    virtual void slot84();
    virtual void slot85(Vec3*, Vec3*);
    virtual void slot86();
    virtual void slot87(unsigned int);
};

class IfaceZ {
public:
    virtual void isNull();
    virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
    virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
    virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
    virtual void slot25();
    virtual float slot26(int, int);
    virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30();
    virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34();
    virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38();
    virtual void slot39(); virtual void slot40(); virtual void slot41();
    virtual int slot42(int, int);
};

class IfaceW {
public:
    virtual void isNull();
    virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5();
    virtual unsigned int slot6();
    virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18();
    virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22();
    virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual float slot26(float, int, void*);
};

struct X {
    char pad0[4];
    Obj8* p4;
    char pad1[0x14];
    IfaceZ* pZ;
    char pad2[0x34];
    IfaceY* pY;
    char pad3[0x70];
    IfaceW* pW;
};

struct Mod {
    char pad[0xd8];
    X* x;
};

struct Self {
    char pad0[0x10];
    Mod* mod;
    char pad1[0xc];
    int unk20;
    char pad2[0x3c];
    unsigned char unk60;
    unsigned char unk61;
};

struct Msg2 {
    int id;
    unsigned char flag;
};


extern "C" void fn_27_65690(Self* self, unsigned int arg1) {
    if (self->mod->x->pY->slot9(0) == 1) {
        if (self->unk60 == 1) {
            if (self->unk20 >= 0) {
                IfaceZ* z;
                void* task = self->mod->x->pY->slot18(0);
                z = self->mod->x->pZ;
                float f = z->slot26(self->unk20, 1);
                if (self->mod->x->pW->slot6() == 1) {
                    IfaceW* w = (IfaceW*)fn_27_8CDD4(task);
                    if (w->slot6() == 1) {
                        f = self->mod->x->pW->slot26(f, z->slot42(self->unk20, 1), w);
                    }
                }
                Obj8* t = (Obj8*)fn_27_8CDF4(task);
                t->slot17(0, f);
            }
            Msg2 m;
            m.id = 10;
            m.flag = 0;
            self->mod->x->pY->slot16(0, &m, 0);
        }
        self->unk61 = 0;
    }
    if (self->mod->x->pY->slot9(0) == 1) {
        if (arg1 == 1) {
            Vec3 a;
            Vec3 b;
            a.x = lbl_27_rodata_8FC;
            a.y = lbl_27_rodata_8FC;
            a.z = lbl_27_rodata_8FC;
            b.x = lbl_27_rodata_8FC;
            b.y = lbl_27_rodata_8FC;
            b.z = lbl_27_rodata_8FC;
            self->mod->x->pY->slot85(&a, &b);
        }
        self->mod->x->pY->slot87(1);
        self->mod->x->pY->slot8(0);
        self->unk61 = 0;
    }
}
