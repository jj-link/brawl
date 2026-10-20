#pragma force_active on
struct ObjectData {
    unsigned char pad[0x3C];
};

class Object : public ObjectData {
public:
    virtual void slot0(), slot1(), slot2(), slot3(), slot4(), slot5(), slot6(), slot7(), slot8(), slot9();
    virtual void slot10(), slot11(), slot12(), slot13(), slot14(), slot15(), slot16(), slot17(), slot18(), slot19();
    virtual void slot20(), slot21(), slot22(), slot23(), slot24(), slot25(), slot26(), slot27(), slot28(), slot29();
    virtual void slot30(), slot31(), slot32(), slot33(), slot34(), slot35(), slot36(), slot37(), slot38(), slot39();
    virtual void slot40(), slot41(), slot42(), slot43(), slot44(), slot45(), slot46(), slot47(), slot48(), slot49();
    virtual void slot50(), slot51(), slot52(), slot53(), slot54(), slot55(), slot56(), slot57(), slot58(), slot59();
    virtual void slot60(), slot61(), slot62(), slot63(), slot64(), slot65(), slot66(), slot67(), slot68(), slot69();
    virtual void slot70(), slot71(), slot72(), slot73(), slot74(), slot75(), slot76(), slot77(), slot78(), slot79();
    virtual void slot80(), slot81(), slot82(), slot83(), slot84(), slot85(), slot86(), slot87(), slot88(), slot89();
    virtual void slot90(), slot91(), slot92(), slot93(), slot94(), slot95(), slot96(), slot97(), slot98(), slot99();
    virtual void slot100(), slot101(), slot102(), slot103(), slot104(), slot105(), slot106(), slot107(), slot108(), slot109();
    virtual void slot110(), slot111(), slot112(), slot113(), slot114(), slot115(), slot116(), slot117(), slot118(), slot119();
    virtual void slot120(), slot121(), slot122();
    virtual void update(float);

    unsigned char pad40[0x88];
    unsigned char enabled;
};

extern "C" void update__9grGimmickFf(Object*, float);

extern "C" void fn_88_57B8(Object* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->enabled) {
        self->update(deltaFrame);
    }
}
