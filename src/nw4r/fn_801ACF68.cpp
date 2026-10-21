#pragma force_active on

struct EntryA { char data[0x10C]; };
struct EntryB { char data[0x30]; };

struct Object {
    void* vtable;
    char pad04[0xE4];
    int value;
    int type;
    int zero;
    unsigned char flag;
    char padF5[3];
    EntryA a[32];
    EntryB b[32];
    char sub[0x10];
    int tail;
};

extern "C" {
extern char lbl_80466318[];

void fn_801AC13C(Object*, int, int, int);
void fn_801B62CC(void*, int, int, int, int, int);
void fn_801A7550(void**, void*);
void fn_801A7558(void**);
void fn_801B5DC0(void**, void*);
void fn_801B5DC8(void**);

Object* fn_801ACF68(Object* self, int a, int b, int c, int d,
                    int e, int f, int g, int h, int i)
{
    fn_801AC13C(self, a, c, d);
    self->vtable = lbl_80466318;
    self->value = b;
    self->type = 2;
    self->zero = 0;
    self->flag = 0;
    fn_801B62CC(self->sub, g, h, e, i, f);
    self->tail = 0;

    for (unsigned j = 0; j < 32; ++j) {
        void* temp;
        fn_801A7550(&temp, (char*)self + (int)(j * 0x10C) + 0xF8);
        fn_801A7558(&temp);
    }

    for (unsigned j = 0; j < 32; ++j) {
        void* temp;
        fn_801B5DC0(&temp, (char*)self + (int)(j * 0x30) + 0x2278);
        fn_801B5DC8(&temp);
    }

    return self;
}
}
