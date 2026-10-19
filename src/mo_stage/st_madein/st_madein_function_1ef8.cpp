#pragma force_active on
typedef long s32;
typedef unsigned long u32;
enum SndID { SndID_Dummy = 0 };
struct Vec3f { float x, y, z; };

class grTenganEvent {
public:
    u32 isEvent() const;
    s32 getPhase() const;
    void setPhase(s32 phase);
    void end();
};

class grGimmick {
public:
    void setPos(Vec3f* pos);
};

class grMadein : public grGimmick {
public:
    void setMotion(u32 motion);
    void startEntity();
    u32 isEndEntity();
};

class stMelee {
public:
    void playSeBasic(SndID id, float value);
};

class EventOffset {
public:
    char padding[0x3dc];
};

class Stage : public stMelee, public EventOffset, public grTenganEvent {
public:
    grMadein* getGround(int id);
};

extern "C" {
extern const float lbl_65_rodata_0[];
u32 fn_27_2793BC(void* ground, float value);
void endEntity__8grMadeinFv(void* self);

void fn_65_1EF8(Stage* self) {
    const float* rd = lbl_65_rodata_0;

    if (!self->isEvent())
        return;

    switch (self->getPhase()) {
    case 0: {
        self->setPhase(self->getPhase() + 1);
        Vec3f pos;
        pos.x = rd[0x1c / 4];
        pos.y = rd[0x14 / 4];
        pos.z = rd[0];
        self->getGround(0x45)->setPos(&pos);
        self->getGround(0x45)->setMotion(0);
        self->getGround(0x45)->startEntity();
        break;
    }
    case 1:
        if (fn_27_2793BC(self->getGround(0x45), rd[0x70 / 4]) == 1) {
            self->playSeBasic((SndID)0x1cb5, rd[0x74 / 4]);
            self->setPhase(self->getPhase() + 1);
        }
        break;
    case 2:
        if (fn_27_2793BC(self->getGround(0x45), rd[0x78 / 4]) == 1) {
            self->playSeBasic((SndID)0x1cb5, rd[0x74 / 4]);
            self->setPhase(self->getPhase() + 1);
        }
        break;
    case 3:
        if (fn_27_2793BC(self->getGround(0x45), rd[0x7c / 4]) == 1) {
            self->playSeBasic((SndID)0x1cb5, rd[0x74 / 4]);
            self->setPhase(self->getPhase() + 1);
        }
        break;
    case 4:
        if (self->getGround(0x45)->isEndEntity() == 1) {
            endEntity__8grMadeinFv(self->getGround(0x45));
            if (*((unsigned char*)self + 0x9e2) == 0)
                self->playSeBasic((SndID)0x1ca3, rd[0]);
            self->end();
        }
        break;
    default:
        break;
    }
}
}
