#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);

struct EarthBase {
    unsigned char padding[0x3C];
};

struct Earth : EarthBase {
    virtual void unused0(), unused1(), unused2(), unused3(), unused4(), unused5(), unused6(), unused7();
    virtual void unused8(), unused9(), unused10(), unused11(), unused12(), unused13(), unused14(), unused15();
    virtual void unused16(), unused17(), unused18(), unused19(), unused20(), unused21(), unused22(), unused23();
    virtual void unused24(), unused25(), unused26(), unused27(), unused28(), unused29(), unused30(), unused31();
    virtual void unused32(), unused33(), unused34(), unused35(), unused36(), unused37(), unused38(), unused39();
    virtual void unused40(), unused41(), unused42(), unused43(), unused44(), unused45(), unused46(), unused47();
    virtual void unused48(), unused49(), unused50(), unused51(), unused52(), unused53(), unused54(), unused55();
    virtual void unused56(), unused57(), unused58(), unused59(), unused60(), unused61(), unused62(), unused63();
    virtual void unused64(), unused65(), unused66(), unused67(), unused68(), unused69(), unused70(), unused71();
    virtual void unused72(), unused73(), unused74(), unused75(), unused76(), unused77(), unused78(), unused79();
    virtual void unused80(), unused81(), unused82(), unused83(), unused84(), unused85(), unused86(), unused87();
    virtual void unused88(), unused89(), unused90(), unused91(), unused92(), unused93(), unused94(), unused95();
    virtual void unused96(), unused97(), unused98(), unused99(), unused100(), unused101(), unused102(), unused103();
    virtual void unused104(), unused105(), unused106(), unused107(), unused108(), unused109(), unused110(), unused111();
    virtual void update1(float);
    virtual void update2(float);
    virtual void update3(float);

    unsigned char padding1[0x88];
    unsigned char active;
};

extern "C" void fn_66_6C30(Earth* self, float deltaFrame)
{
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->update1(deltaFrame);
        self->update2(deltaFrame);
        self->update3(deltaFrame);
    }
}
