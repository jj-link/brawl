#pragma force_active on

typedef unsigned char u8;

extern "C" float randf__Fv();
extern "C" const float lbl_63_rodata_138[];

struct MotionData {
    char pad[0x60];
    float minimum;
    float maximum;
};

struct Position {
    float x, y, z;
};

struct SharedData {
    Position positions[8];
    u8 active;
    u8 index;
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27(unsigned long);
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual MotionData* slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66(float, unsigned long);
    virtual float slot67(unsigned long);
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96(unsigned long, unsigned long);
    virtual void slot97(unsigned long, unsigned long);
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114(int, int, int, float*);
};

struct StageObject : Object_vptr_3c {
    char pad40[0x24];
    float rate;
    char pad68[4];
    u8 flags : 1;
    char pad6d[0xe3];
    u8 state;
    char pad151[3];
    float timer;
    char pad158[5];
    u8 flag15d;
    char pad15e[2];
    float previousFrame;
    float motionFrame;
    char pad168[0xc];
    SharedData* shared;
    u8* current;
    u8 expected;
    char pad17d[3];
    Position position;
    u8 mode;
    u8 motionStarted;
};

extern "C" void fn_63_10F18(StageObject* self, float delta) {
    const float* c = lbl_63_rodata_138;
    MotionData* data = self->slot40();

    if (data != 0) {
        float timer = self->timer - delta;
        self->timer = timer;
        if (timer < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            self->slot114(1, 0, 1, 0);
            self->slot27(0);
            self->slot97(0, 0);
            self->shared->active = 0;
            self->state = 1;
            break;

        case 1:
            if (*self->current == self->expected) {
                self->slot114(0, 1, 1, &self->motionFrame);
                self->slot66(self->motionFrame, 0);
                self->previousFrame = self->motionFrame;
                if (self->rate > c[0])
                    self->rate *= c[1];
                self->motionStarted = 0;
                self->state = 3;
            }
            break;

        case 3:
            if (*self->current != self->expected) {
                self->slot114(0, 0, 1, &self->motionFrame);
                if (self->rate < c[0])
                    self->rate *= c[1];
                self->slot97(0, 0);
                self->state = 4;
            } else if (self->shared->active == 1) {
                switch (self->mode) {
                case 0:
                    self->slot27(0);
                    break;
                default:
                    break;
                }
                self->slot97(0, 0);
                self->state = 5;
            } else {
                if (!self->flags)
                    self->slot27(1);

                if (self->motionStarted == 0) {
                    if (self->slot67(0) > self->previousFrame &&
                        self->flag15d == 0) {
                        self->slot114(1, 0, 0, 0);
                        self->motionStarted = 1;
                        self->slot96(0, 0);
                    } else {
                        self->previousFrame = self->slot67(0);
                    }
                }

                if (c[0] == self->timer) {
                    float r = randf__Fv();
                    if (r < c[2])
                        self->shared->index = 0;
                    else if (r < c[3])
                        self->shared->index = 1;
                    else if (r < c[4])
                        self->shared->index = 2;
                    else
                        self->shared->index = 3;

                    self->timer = data->minimum +
                        (data->maximum - data->minimum) * randf__Fv();
                }
            }
            break;

        case 5:
            if (*self->current != self->expected) {
                self->slot114(0, 0, 1, &self->motionFrame);
                if (self->rate < c[0])
                    self->rate *= c[1];
                self->slot97(0, 0);
                self->state = 4;
            } else if (self->shared->active == 0) {
                self->slot27(1);
                self->slot96(0, 0);
                self->state = 3;
            } else {
                switch (self->mode) {
                case 2:
                    if (self->shared->index < 4)
                        self->slot27(1);
                    else
                        self->slot27(0);
                    break;
                default:
                    break;
                }
            }
            break;

        case 4:
            if (self->slot67(0) >= self->motionFrame)
                self->state = 0;
            break;
        }

        self->position = self->shared->positions[self->shared->index];
    }
}
