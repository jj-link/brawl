#pragma force_active on
struct Data {
    unsigned char pad0[0x8];
    unsigned char field8;
    unsigned char pad9[0x90];
    unsigned char field99;
    unsigned char pad9A[0x5B];
    unsigned char fieldF5;
    unsigned char padF6[0x5B];
    unsigned char field151;
    unsigned char pad152[0x5B];
    unsigned char field1AD;
};
struct Obj {
    unsigned char pad0[0x44];
    Data* data;
    unsigned char pad48[0x89];
    unsigned char d1, d2, d3;
    unsigned char padD4[0x19C];
    int counter;
    int arr[4];
    int field284;
    unsigned char field288;
};
extern "C" void fn_27_2498DC(Obj*);
inline void add(Obj* self, int value) {
    if (*((unsigned char*)self->data + 0x99 + value * 0x5c) != 3) {
        self->arr[self->counter] = value;
        self->counter = self->counter + 1;
    }
}
extern "C" void fn_27_252658(Obj* self) {
    fn_27_2498DC(self);
    self->counter = 0;
    self->arr[0] = 0;
    self->arr[1] = 0;
    self->arr[2] = 0;
    self->arr[3] = 0;
    for (int i = 0; i < 4; i++) add(self, i);
    self->field284 = 0;
    self->field288 = 0;
    self->d1 = 0;
    if (((self->data->field8 >> 2) & 0x3F) == 8u) self->d3 = 1;
}