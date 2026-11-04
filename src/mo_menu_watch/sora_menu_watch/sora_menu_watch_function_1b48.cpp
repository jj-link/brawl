#pragma force_active on
struct Target {
    char pad0[0x348];
    unsigned char ready;
    char pad349[3];
    int result;
    char pad350[0x34];
    unsigned short time;
    char pad386[6];
    int value;
};
struct Object {
    char pad0[0x490];
    char area[0x5c];
    int state;
    int status;
    int value;
    int timer;
    int timer2;
    char pad500[0x2c];
    int duration;
    char pad530[0x829];
    unsigned char flag;
    char padD5A[2];
    Target* target;
};
extern "C" void fn_80155E14(Target*);
extern "C" void fn_15_1E4C(Object*);
extern "C" void fn_15_1D7C(Object*, void*);
extern "C" int fn_800CBCB0(void*, int*);
extern "C" void OSReport(const char*, ...);
extern void* g_muWifiInterfaceTask;
extern int lbl_805A0448;
extern char lbl_15_data_1D0[];
extern char lbl_15_data_1F8[];
extern "C" void fn_15_1B48(Object* self) {
    if (self->state == 6) {
        unsigned char ready;
        if (self->flag) ready = 1;
        else ready = self->target->ready;
        if (ready) self->state = 0;
    } else if (self->state == 1) {
        if (--self->timer <= 0) {
            self->state = 2;
            if (self->flag) self->timer2 = 180;
            else fn_80155E14(self->target);
        }
    } else if (self->state == 2) {
        int ready;
        if (self->flag) {
            if (--self->timer2 <= 0) ready = 1;
            else goto not_ready;
        } else if (self->target->ready) ready = 1;
        else {
        not_ready:
            ready = 0;
        }
        if (ready) {
            int next;
            if (self->flag) next = 3;
            else {
                switch (self->target->result) {
                case 0: next = 3; break;
                case 2: next = 5; break;
                case 3: next = 4; break;
                default: next = 4; break;
                }
            }
            switch (next) {
            case 3:
                fn_15_1E4C(self);
                int duration;
                if (self->flag) duration = 900;
                else duration = self->target->time * 60;
                self->duration = duration;
                fn_15_1D7C(self, self->area);
                break;
            case 5:
                break;
            case 4:
                self->status = 0;
                self->value = self->target->value;
                break;
            }
            self->state = next;
            return;
        }
        goto check5;
    } else {
    check5:
      if (self->state == 5) {
        if (lbl_805A0448 == 0) {
            OSReport(lbl_15_data_1D0);
            self->status = fn_800CBCB0(g_muWifiInterfaceTask, &self->value);
            if (self->status) self->state = 4;
        } else OSReport(lbl_15_data_1F8);
      }
    }
}