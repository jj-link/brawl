#pragma force_active on
struct GroundBase {
    unsigned char pad0[0x3c];
};

struct Ground : GroundBase {
    virtual void unused0(), unused1(), unused2(), unused3(), unused4(), unused5(), unused6(), unused7(), unused8(), unused9(), unused10(), unused11(), unused12(), unused13();
    virtual void unused14(), unused15(), unused16(), unused17(), unused18(), unused19(), unused20(), unused21(), unused22(), unused23(), unused24(), unused25(), unused26(), unused27();
    virtual void unused28(), unused29(), unused30(), unused31(), unused32(), unused33(), unused34(), unused35(), unused36(), unused37(), unused38(), unused39(), unused40(), unused41();
    virtual void unused42(), unused43(), unused44(), unused45(), unused46(), unused47(), unused48(), unused49(), unused50(), unused51(), unused52(), unused53(), unused54(), unused55();
    virtual void unused56(), unused57(), unused58(), unused59(), unused60(), unused61(), unused62(), unused63(), unused64(), unused65(), unused66(), unused67(), unused68(), unused69();
    virtual void unused70(), unused71(), unused72(), unused73(), unused74(), unused75(), unused76(), unused77(), unused78(), unused79(), unused80(), unused81(), unused82(), unused83();
    virtual void unused84(), unused85(), unused86(), unused87(), unused88(), unused89(), unused90(), unused91(), unused92(), unused93(), unused94(), unused95(), unused96(), unused97();
    virtual void unused98(), unused99(), unused100(), unused101(), unused102(), unused103(), unused104(), unused105(), unused106(), unused107(), unused108(), unused109(), unused110(), unused111();
    virtual void unused112(), unused113(), unused114(), unused115(), unused116(), unused117(), unused118(), unused119(), unused120(), unused121(), unused122(), unused123(), unused124(), unused125();
    virtual void call(int, int, int, void*);

    unsigned char pad1[0x110];
    unsigned char state;
    unsigned char pad2[0x47];
    unsigned char data[1];
};

extern "C" void setEnableCollisionStatus__6GroundFb(void*, bool);

extern "C" void fn_51_10F40(Ground* self) {
    switch (self->state) {
    case 1:
        self->call(0, 0, 0, self->data);
        setEnableCollisionStatus__6GroundFb(self, false);
        self->state = 4;
        break;
    }
}
