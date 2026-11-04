#pragma force_active on
struct Target {
    char pad[0x82];
    unsigned short a, b, c;
    char pad88[4];
    unsigned char ready;
    char pad8d[3];
    int result;
};
struct Self {
    char pad[0x48];
    Target* target;
    unsigned char done;
    char pad4d[3];
    int result;
    unsigned short a, b, c;
    char pad5a[2];
    unsigned int state;
};
extern "C" {
void fn_8014F490(Target*, int, int);
long long fn_8014CE68(Target*);
void fn_8014FEC8(long long);
int fn_8014D108(Target*, int);
void fn_801505B0(int);
void fn_801505DC(int);
int fn_800305B0(int);
int fn_80150594();
int fn_8014F584(Target*, int);
int fn_801505C0();
unsigned int fn_8014FDF0();
int fn_8014D794(Target*);
void fn_8014D854(Target*);
void fn_8014FE04(int);
void fn_8014DBDC(Target*);
}
extern "C" void fn_801583AC(Self* self) {
    switch (self->state) {
    case 0:
        break;
    case 1:
        fn_8014F490(self->target, 4, 0);
        self->state = 2;
        break;
    case 2:
        if (self->target->ready) {
            if (self->target->result == 0) {
                self->state = 3;
            } else {
                self->state = 0;
                self->done = 1;
            }
        }
        break;
    case 3:
        fn_8014FEC8(fn_8014CE68(self->target));
        fn_801505B0(fn_8014D108(self->target, 1));
        fn_801505DC(fn_8014D108(self->target, 2));
        self->state = 4;
        break;
    case 4:
        if (fn_800305B0(3) && fn_80150594() && fn_8014F584(self->target, 0)) {
            self->state = 5;
        } else {
            self->state = 6;
        }
        break;
    case 5:
        if (self->target->ready) {
            switch (self->target->result) {
            case 0: self->result = 0; break;
            case -1: self->result = 3; break;
            case -2: self->result = 1; break;
            case -3: self->result = 2; break;
            }
            if ((unsigned int)(self->result - 1) <= 1) {
                self->a = self->target->a;
                self->b = self->target->b;
                self->c = self->target->c;
            }
            self->state = 6;
        }
        break;
    case 6:
        if (fn_801505C0()) {
            if (fn_8014FDF0() == 1) {
                if (fn_8014D794(self->target)) {
                    fn_8014D854(self->target);
                } else {
                    fn_8014FE04(0);
                }
            } else if (fn_8014D794(self->target)) {
                fn_8014DBDC(self->target);
            }
        } else if (fn_8014FDF0() == 1) {
            fn_8014FE04(0);
        }
        self->state = 0;
        self->done = 1;
        break;
    }
}
