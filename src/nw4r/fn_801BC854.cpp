#pragma force_active on
extern float lbl_805A34A8;
extern float lbl_805A34AC;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual Object_vptr_0* slot24();

    char pad[0x50];
    float start;
    float end;
    int duration;
    int elapsed;
    char pad64[3];
    unsigned char state;
    unsigned char active;

    void reset(float current, float target, int frames) {
        start = current;
        end = target;
        duration = frames;
        elapsed = 0;
    }

    float value() {
        if (elapsed >= duration)
            return end;
        return start + ((float)elapsed * (end - start)) / (float)duration;
    }
};

extern "C" void fn_801BC854(Object_vptr_0* self, int state, int duration) {
    Object_vptr_0* object = self->slot24();
    if (state) {
        float value = self->value();
        int frames = (int)((float)duration * value);
        self->active = 1;
        if (frames <= 0)
            frames = 1;
        self->reset(self->value(), lbl_805A34A8, frames);
    } else {
        if (self->state != (unsigned int)state)
            object->slot3(0);
        float value = self->value();
        int frames = (int)((float)duration * (lbl_805A34AC - value));
        self->active = 1;
        if (frames <= 0)
            frames = 1;
        self->reset(self->value(), lbl_805A34AC, frames);
    }
    self->state = state;
}