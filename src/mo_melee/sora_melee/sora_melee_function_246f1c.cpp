#pragma force_active on

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
    virtual void slot6();
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
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
};

struct Obj {
    char pad[0x40];
    unsigned char state;
    unsigned char pad41;
    unsigned char f42;
    unsigned char f43;
    char pad44[8];
    float timer;
    char pad50[4];
    unsigned char flags : 1;
    unsigned char rest : 7;
    char pad55[3];
    Object_vptr_3c* objects[7];
    void* ptr;
};

extern "C" {
extern void* g_ftManager;
extern const float lbl_27_rodata_3FB0;

void fn_27_242404(void*);
void fn_27_109318(void*);

void fn_27_246F1C(Obj* self) {
    if (self->f43 != 1 && self->f42 != 1) {
        switch ((int)self->state) {
        case 4:
            return;
        case 3:
            if (self->ptr) {
                fn_27_242404(self->ptr);
            }
            for (int i = 0; i < 7; i++) {
                if (self->objects[i]) {
                    self->objects[i]->slot35();
                }
            }
            fn_27_109318(g_ftManager);
            self->flags = 1;
            self->state = 5;
            self->timer = lbl_27_rodata_3FB0;
            break;
        }
    }
}
}
