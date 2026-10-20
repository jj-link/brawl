#pragma force_active on
struct Base {
    unsigned char padding0[0x3c];
};

struct Object : Base {
    virtual void slot0(), slot1(), slot2(), slot3(), slot4(),
                 slot5(), slot6(), slot7(), slot8(), slot9(),
                 slot10(), slot11(), slot12(), slot13(), slot14(),
                 slot15(), slot16(), slot17(), slot18(), slot19(),
                 slot20(), slot21(), slot22(), slot23(), slot24(),
                 slot25(), slot26(), slot27(), slot28(), slot29(),
                 slot30(), slot31(), slot32(), slot33(), slot34(),
                 slot35(), slot36(), slot37(), slot38(), slot39(),
                 slot40(), slot41(), slot42(), slot43(), slot44(),
                 slot45(), slot46(), slot47(), slot48(), slot49(),
                 slot50(), slot51(), slot52(), slot53(), slot54(),
                 slot55(), slot56(), slot57(), slot58(), slot59(),
                 slot60(), slot61(), slot62(), slot63(), slot64(),
                 slot65(), slot66(), slot67(), slot68(), slot69(),
                 slot70(), slot71(), slot72(), slot73(), slot74(),
                 slot75(), slot76(), slot77(), slot78(), slot79(),
                 slot80(), slot81(), slot82(), slot83(), slot84(),
                 slot85(), slot86(), slot87(), slot88(), slot89(),
                 slot90(), slot91(), slot92(), slot93(), slot94(),
                 slot95(), slot96(), slot97(), slot98(), callback();

    unsigned char padding40[0x2d];
    unsigned char flags;
    unsigned char padding6e[0x192];
    unsigned char state;
};

extern "C" void fn_40_3AEC4(Object*, int);

extern "C" void fn_40_3B0A4(Object* self, int value)
{
    fn_40_3AEC4(self, value);
    if (value == 3) {
        self->state = 1;
        if ((self->flags >> 6) & 1) {
            self->callback();
        }
    }
}
