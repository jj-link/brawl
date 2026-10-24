#pragma force_active on
#pragma switch_tables on
typedef unsigned char u8;

struct Entry {
    u8 pad[0x0C];
    float x;
    float y;
    float z;
    u8 active;
    u8 pad2[0x0F];
};

struct Base {
    u8 pad[0x3C];
};

#define A(n) virtual void a##n();
#define B(n) virtual void b##n();
#define C(n) virtual void c##n();

struct Object : Base {
    A(0) A(1) A(2) A(3) A(4) A(5) A(6) A(7) A(8) A(9)
    A(10) A(11) A(12) A(13) A(14) A(15) A(16) A(17) A(18) A(19)
    A(20) A(21) A(22) A(23) A(24) A(25) A(26) A(27) A(28) A(29)
    A(30) A(31) A(32) A(33) A(34) A(35) A(36) A(37) A(38) A(39)
    virtual int ready();
    B(0) B(1) B(2) B(3) B(4) B(5) B(6) B(7) B(8) B(9)
    B(10) B(11) B(12) B(13) B(14) B(15) B(16) B(17) B(18) B(19)
    B(20) B(21) B(22) B(23) B(24) B(25) B(26) B(27) B(28) B(29)
    B(30) B(31) B(32) B(33) B(34) B(35) B(36) B(37) B(38) B(39)
    B(40) B(41) B(42) B(43) B(44) B(45) B(46) B(47) B(48) B(49)
    B(50) B(51) B(52) B(53) B(54) B(55) B(56) B(57) B(58) B(59)
    B(60) B(61) B(62) B(63) B(64) B(65) B(66) B(67) B(68) B(69)
    B(70) B(71) B(72) B(73) B(74) B(75) B(76) B(77) B(78) B(79)
    B(80) B(81)
    virtual void update();
    C(0) C(1) C(2) C(3) C(4) C(5) C(6) C(7) C(8) C(9)
    C(10) C(11) C(12) C(13) C(14) C(15) C(16) C(17) C(18)
    virtual void other();

    u8 pad1[0x24];
    float value;
    u8 pad2[0xF0];
    u8 state;
    u8 pad3[3];
    float timer;
    float wait;
    u8 pad4[0x10];
    u8 count;
    u8 index;
    u8 pad5[2];
    Entry* entries;
};

#undef A
#undef B
#undef C

extern "C" void fn_68_BB4C(Object*);
extern "C" const float lbl_68_rodata_198[];

extern "C" void fn_68_10114(Object* self) {
    const float* c = lbl_68_rodata_198;
    fn_68_BB4C(self);
    if (self->ready()) {
        self->value = c[0];
        switch (self->state) {
        case 3:
        case 7:
        case 11:
            if (c[1] == self->timer) {
                if (self->entries[self->index].active == 1) {
                    self->entries[self->index].active = 0;
                    Entry* e = &self->entries[self->index];
                    e->x = c[1];
                    e->y = c[2];
                    e->z = c[1];
                } else {
                    self->entries[self->index].active = 1;
                    Entry* e = &self->entries[self->index];
                    e->x = c[1];
                    e->y = c[1];
                    e->z = c[1];
                }
                self->update();
                self->wait = c[3];
            }
            return;
        case 1:
        case 5:
        case 9:
            self->other();
            return;
        case 13:
        case 14:
        case 15:
            if (c[1] == self->timer) {
                self->count++;
                if (self->count > 3) self->count = 3;
                self->update();
            }
            return;
        }
    }
}