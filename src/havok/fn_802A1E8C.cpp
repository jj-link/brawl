#pragma force_active on
struct Msg {
    unsigned char a;
    unsigned char b;
    unsigned short c;
};

struct Queue {
    Msg msgs[8];
    unsigned char pad;
    unsigned char count;
    unsigned char flag;
};

extern "C" void fn_802A1E8C(Queue* self, int index) {
    self->flag = 0;
    self->msgs[index] = self->msgs[self->count - 1];
    self->count--;
}