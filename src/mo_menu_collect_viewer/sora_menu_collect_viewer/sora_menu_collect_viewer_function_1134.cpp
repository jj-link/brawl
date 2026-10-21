#pragma force_active on
#pragma opt_propagation off

extern "C" void fn_800FABEC(void*);
extern "C" void fn_800FAC58(void*, const void*, int, int);
extern "C" void loadMenuSound__6muMenuFv(void);
extern char lbl_6_data_0[];

struct Viewer {
    char pad[0x1AC];
    char* data;
};

extern "C" void fn_6_1134(Viewer* self)
{
    int zero;
    unsigned long base = (unsigned long)lbl_6_data_0;
    char* data = self->data;
    const void* p = (void*)(base + 4);

    fn_800FABEC(data + 0xE4);
    zero = 0;
    *(int*)(data + 0xD0) = zero;
    data[0xFC] = zero;
    fn_800FAC58(data + 0xE4, p, 0x2B, 0);

    data = self->data;
    const void* p2 = (void*)(base + 0x2C);
    fn_800FABEC(data + 0x48);
    *(int*)(data + 0x34) = zero;
    data[0x60] = zero;
    fn_800FAC58(data + 0x48, p2, 0x2B, 0);

    data = self->data;
    const void* p3 = (void*)(base + 0x50);
    fn_800FABEC(data + 0x7C);
    *(int*)(data + 0x68) = zero;
    data[0x94] = zero;
    fn_800FAC58(data + 0x7C, p3, 0x2B, 0);

    fn_800FAC58(self->data + 0x1CB0, (void*)(base + 0x70), 0x2B, 0);
    fn_800FAC58(self->data + 0x1CC8, (void*)(base + 0x8C), 0x2B, 0);
    loadMenuSound__6muMenuFv();
}
