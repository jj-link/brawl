#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct sndSystem;
extern "C" {
extern sndSystem* g_sndSystem;
int loadSoundGroup__9sndSystemF10SndGroupIDib(sndSystem*, u32, int, int);
void freeGroup__9sndSystemFii(sndSystem*, int, int);
int fn_80073D08(sndSystem*, u32);
}

struct TaskBase { u8 pad[0x3c]; };
struct Task : TaskBase {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual u32 getId();
    u32 pad40;
    u8 state;
    u8 pad45;
    u8 enabled;
    u8 flag;
    int handle;
    u32 id;
    int heap;
};

extern "C" void fn_27_2419AC(Task* self) {
    if (self->enabled != 0) {
        switch ((int)self->state) {
        case 0:
            if (self->flag == 1) {
                self->state = 6;
            }
            self->id = self->getId();
            if (self->id != 0xFFFFFFFF) {
                self->state = 1;
            }
            break;
        case 1:
            self->handle = loadSoundGroup__9sndSystemF10SndGroupIDib(g_sndSystem, self->id, self->heap, 1);
            self->state = 2;
            break;
        case 2:
            if (fn_80073D08(g_sndSystem, self->id) != 0) {
                self->state = 3;
            }
            break;
        case 3:
            if (self->flag == 1 || self->id != self->getId()) {
                self->state = 5;
            }
            break;
        case 5:
            freeGroup__9sndSystemFii(g_sndSystem, self->handle, self->heap);
            self->handle = -1;
            if (self->flag == 1) {
                self->state = 6;
            } else {
                self->state = 0;
            }
            break;
        }
    }
}
