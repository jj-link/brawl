#pragma force_active on
#pragma pool_data on

typedef unsigned char u8;

struct Data {
    char pad[0x38];
    float value;
};

struct Entry {
    char pad[0x20];
    float value;
    u8 flag;
    char pad2[3];
};

struct Base {
    char pad[0x3c];
};

struct Self : Base {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual Data* getData();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void setPair(int, int);
    virtual void setOne(int);
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void unused133();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual void unused139();
    virtual void unused140();
    virtual void update2();
    virtual void motion(int, int, int, float*);

    char pad40[0x110];
    u8 state;
    char pad151[3];
    float frame;
    char pad158[4];
    float motionFrame;
    char pad160[0xe];
    u8 flag16e;
    char pad16f;
    float rate;
    u8 mode;
    u8 index;
    char pad176[2];
    Entry* entries;
    char pad17c[0xd];
    u8 flag189;
    char pad18a[0x23];
    u8 flag1ad;
    char pad1ae[4];
};

extern "C" const float lbl_68_rodata_148[];

extern "C" void fn_68_F444(Self* self) {
    const float* constants = lbl_68_rodata_148;
    Data* data = self->getData();
    if (data != 0) {
        switch (self->mode) {
        case 1:
            self->motion(0, 0, 0, &self->motionFrame);
            break;
        case 2:
            self->motion(4, 0, 0, &self->motionFrame);
            break;
        case 3:
            self->motion(8, 0, 0, &self->motionFrame);
            break;
        }
        self->motionFrame = data->value - constants[10];
        self->setPair(0, 0);
        self->setOne(0);
        self->flag189 = 0;
        self->flag16e = 0;
        float val = self->entries[self->index].value;
        if (val >= constants[0] && val <= constants[3]) {
            if (val < constants[11])
                self->rate = constants[7];
            else if (val > constants[12])
                self->rate = constants[3];
            else
                self->rate = constants[13];
        }
        self->update2();
        self->flag1ad = 1;
        self->entries[self->index].flag = 1;
        self->state = 0xc;
    }
}
