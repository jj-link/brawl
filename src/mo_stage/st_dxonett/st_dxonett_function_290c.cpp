#pragma force_active on
struct GimmickPrefix {
    unsigned char padding[0x3C];
};

struct Gimmick : GimmickPrefix {
    virtual void unused0(), unused1(), unused2(), unused3(), unused4(), unused5(), unused6(), unused7(), unused8(), unused9();
    virtual void unused10(), unused11(), unused12(), unused13(), unused14(), unused15(), unused16(), unused17(), unused18(), unused19();
    virtual void unused20(), unused21(), unused22(), unused23(), unused24(), unused25(), unused26(), unused27(), unused28(), unused29();
    virtual void unused30(), unused31(), unused32(), unused33(), unused34(), unused35(), unused36(), unused37(), unused38(), unused39();
    virtual void unused40(), unused41(), unused42(), unused43(), unused44(), unused45(), unused46(), unused47(), unused48(), unused49();
    virtual void unused50(), unused51(), unused52(), unused53(), unused54(), unused55(), unused56(), unused57(), unused58(), unused59();
    virtual void unused60(), unused61(), unused62(), unused63(), unused64(), unused65(), unused66(), unused67(), unused68(), unused69();
    virtual void unused70(), unused71(), unused72(), unused73(), unused74(), unused75(), unused76(), unused77(), unused78(), unused79();
    virtual void unused80(), unused81(), unused82(), unused83(), unused84(), unused85(), unused86(), unused87(), unused88(), unused89();
    virtual void unused90(), unused91(), unused92(), unused93(), unused94(), unused95(), unused96(), unused97(), unused98(), unused99();
    virtual void unused100(), unused101(), unused102(), unused103(), unused104(), unused105(), unused106(), unused107(), unused108(), unused109();
    virtual void unused110(), unused111(), unused112();
    virtual void updateFirst(float);
    virtual void updateSecond(float);

    unsigned char padding[0x88];
    unsigned char active;
};

extern "C" void update__9grGimmickFf(Gimmick*, float);

extern "C" void fn_78_290C(Gimmick* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->updateFirst(deltaFrame);
        self->updateSecond(deltaFrame);
    }
}
