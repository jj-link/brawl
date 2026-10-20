#pragma force_active on
struct Data {
    unsigned char pad[0x59];
    unsigned char value;
};

struct Holder {
    Data* data;
};

struct Object {
    unsigned char pad[0x2c];
    Holder* holder;
};

extern "C" int fn_27_12228(Object* self) {
    switch (self->holder->data->value % 10) {
    case 0: break;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return 0;
}
