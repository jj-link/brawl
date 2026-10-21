#pragma force_active on
extern "C" {
extern char g_HeapInfos[];
extern int g_IfMngr;
void fn_800DBF08(int, void*);
void fn_800DC57C(int, void*);
}

struct Obj {
    char pad[0xf4];
    unsigned char a;
    unsigned char b;
    char pad2[0x5a];
    unsigned char c;
    unsigned char d;
};

struct Self {
    char pad[0x40];
    Obj* obj;
};

extern "C" void fn_27_2409E8(Self* self) {
    if (self->obj->a == 0x3c)
        self->obj->b = 1;
    if (self->obj->c == 0x3d)
        self->obj->d = 1;
    if (*(int*)(g_HeapInfos + 0x280) != 0) {
        fn_800DBF08(g_IfMngr, self->obj);
        fn_800DC57C(g_IfMngr, self->obj);
        if (self->obj->a == 0x3c)
            self->obj->b = 3;
        if (self->obj->c == 0x3d)
            self->obj->d = 3;
    }
}
