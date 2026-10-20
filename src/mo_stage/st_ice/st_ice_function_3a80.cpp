#pragma force_active on
struct IceBase {
    unsigned char padding[0x3C];
};

struct Ice : IceBase {
    virtual void unused0(), unused1(), unused2(), unused3(), unused4(), unused5(), unused6(), unused7(), unused8();
    virtual void unused9(), unused10(), unused11(), unused12(), unused13(), unused14(), unused15(), unused16(), unused17();
    virtual void unused18(), unused19(), unused20(), unused21(), unused22(), unused23(), unused24(), unused25(), unused26();
    virtual void unused27(), unused28(), unused29(), unused30(), unused31(), unused32(), unused33(), unused34(), unused35();
    virtual void unused36(), unused37(), unused38(), unused39(), unused40(), unused41(), unused42(), unused43(), unused44();
    virtual void unused45(), unused46(), unused47(), unused48(), unused49(), unused50(), unused51(), unused52(), unused53();
    virtual void unused54(), unused55(), unused56(), unused57(), unused58(), unused59(), unused60(), unused61(), unused62();
    virtual void unused63(), unused64(), unused65(), unused66(), unused67(), unused68(), unused69(), unused70(), unused71();
    virtual void unused72(), unused73(), unused74(), unused75(), unused76(), unused77(), unused78(), unused79(), unused80();
    virtual void unused81(), unused82(), unused83(), unused84(), unused85(), unused86(), unused87(), unused88(), unused89();
    virtual void unused90(), unused91(), unused92(), unused93(), unused94(), unused95(), unused96(), unused97(), unused98();
    virtual void unused99(), unused100(), unused101(), unused102(), unused103(), unused104(), unused105(), unused106(), unused107();
    virtual void unused108(), unused109(), unused110(), unused111(), unused112(), unused113(), unused114(), unused115(), unused116();
    virtual void update();

    unsigned char padding1[0x10C];
    int state;
    unsigned char padding2[0x64];
    unsigned char done;
};

extern "C" void fn_62_3A80(Ice* self) {
    if (self->done != 1) {
        self->update();
        if (self->state != 0) {
            self->done = 1;
        }
    }
}
