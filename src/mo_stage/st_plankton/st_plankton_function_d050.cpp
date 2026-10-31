#pragma force_active on

extern "C" const float lbl_74_rodata_1C0;

struct PlanktonData {
    float f0;
    float f4;
    unsigned char type;
    unsigned char index;
};

struct EntityRecord {
    unsigned char value[4];
};

struct PlanktonEntity {
    unsigned char pad00[0x7C];
    EntityRecord first[15];
    EntityRecord second[16];
};

struct PlanktonBase {
    unsigned char pad[0x3C];
};

#define SLOT(n) virtual void vf##n();

struct Plankton : PlanktonBase {
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28)
    virtual void setEnabled(int);
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41)
    virtual int* getEntity();
    SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52)
    SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68)
    virtual float getFrame(int);
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108)
    SLOT(109) SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115)
    virtual void setMotion(int, int, int, float*);

    unsigned char pad40[0x6C - 0x40];
    unsigned char flags;
    unsigned char pad6D[0x150 - 0x6D];
    unsigned char state;
    unsigned char pad151[7];
    PlanktonData* data;
    unsigned char pad15C[4];
    unsigned char pad160[4];
    unsigned char pad164[0x10];
    float timer;
};

#undef SLOT

extern "C" void fn_74_D050(Plankton* self) {
    switch (self->state) {
    case 0:
        self->setMotion(1, 0, 1, 0);
        self->setEnabled(0);
        self->state = 1;
    case 1:
        if (self->data->type == 0) {
            self->setMotion(0, 0, 1, &self->timer);
            int* entity = self->getEntity();
            if (entity) {
                unsigned char* data = (unsigned char*)self->data;
                PlanktonEntity* records = (PlanktonEntity*)entity;
                EntityRecord* a = &records->first[data[9]];
                self->pad15C[0] = a->value[0];
                self->pad15C[1] = a->value[1];
                self->pad15C[2] = a->value[2];
                self->pad15C[3] = a->value[3];
                EntityRecord* b = &records->second[data[9]];
                self->pad160[0] = b->value[0];
                self->pad160[1] = b->value[1];
                self->pad160[2] = b->value[2];
                self->pad160[3] = b->value[3];
                self->state = 8;
            }
        }
        break;
    case 8:
        if (!((self->flags >> 7) & 1)) {
            self->setEnabled(1);
        }
        if (self->getFrame(0) >= self->timer) {
            PlanktonData* data = self->data;
            data->f0 = lbl_74_rodata_1C0;
            data->f4 = lbl_74_rodata_1C0;
            self->data->type = 3;
            self->data->index = 0;
            self->setEnabled(0);
            self->state = 0;
        }
        break;
    }
}
