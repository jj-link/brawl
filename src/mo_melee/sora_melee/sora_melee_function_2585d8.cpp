#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

struct Data {
    u8 pad0[8];
    u8 kind;
    u8 pad9[0x17];
    int value;
};

struct Object {
    u8 pad0[0x2c];
    u8 flags;
    u8 pad2d[0x0f];
    const void* table;
    u8 pad40[4];
    Data* data;
    u8 pad48[0xd3];
    u8 f11b;
    u8 f11c;
    u8 f11d;
    u8 f11e;
    u8 f11f;
    int f120;
    u8 f124;
    s8 f125;
    bool f126;
    u8 pad127;
    int f128;
    int f12c;
    int f130;
    int f134;
};

extern "C" {
    void fn_27_255808(Object*, const void*);
    extern const char lbl_27_data_53440[];
    extern const char lbl_27_data_535B8[];
    extern int lbl_27_data_53438;
}

extern "C" Object* fn_27_2585D8(Object* self, s8 arg) {
    fn_27_255808(self, lbl_27_data_53440);

    self->table = lbl_27_data_535B8;
    self->f11b = 0;
    Data* data = self->data;
    self->f11c = 0;
    self->f11d = 0;
    self->f11e = 0;
    self->f11f = 0;
    self->f120 = 0;
    self->f124 = 0;
    self->f125 = arg;
    self->f126 = 0;
    self->f128 = lbl_27_data_53438;
    self->f12c = 0;
    self->f130 = lbl_27_data_53438;
    self->f134 = 0;

    switch ((data->kind >> 2) & 0x3f) {
    case 14:
    {
        bool b = data->value == 0;
        self->f124 = 1;
        self->f126 = b;
        break;
    }
    case 16:
    case 18:
        self->f126 = 1;
        self->f124 = 1;
        break;
    case 28:
        break;
    }

    self->flags &= ~2;
    return self;
}
