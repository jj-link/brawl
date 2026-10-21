#pragma force_active on
extern "C" {

extern const float lbl_88_rodata_108;

struct Base {
    int data[15];
};

struct Homerun : Base {
#define V(n) virtual void f##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
#undef V
    virtual void action(unsigned char*, int, int);

    unsigned char pad[0x110];
    unsigned char state;
    unsigned char pad2[3];
    float timer;
    unsigned char* arr;
    int pad3[10];
    int values[12];
};

void fn_88_5814(Homerun* self, float f) {
    self->timer -= f;
    if (self->timer < lbl_88_rodata_108)
        self->timer = lbl_88_rodata_108;

    switch (self->state) {
    case 0:
        for (unsigned char i = 0; i < 12; i++) {
            self->action(self->arr + i * 0xC, 0, self->values[i]);
        }
        self->state = 1;
        // fallthrough
    case 1:
        self->state = 2;
        break;
    case 2:
        break;
    }
}

}
