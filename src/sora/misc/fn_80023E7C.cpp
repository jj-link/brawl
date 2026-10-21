#pragma force_active on
typedef unsigned short u16;

struct Obj {
    char pad[0x36];
    u16 a;
    u16 b;
    float c;
};

extern "C" float fn_801F17B8(u16, u16);
extern "C" void fn_80023CA8(void*);
extern "C" void fn_80023DD4(void*);
extern "C" void fn_801E8034(void (*)(void*));
extern "C" void fn_801F0C20(void (*)(void*));

extern "C" void fn_80023E7C(Obj* self) {
    self->c = fn_801F17B8(self->a, self->b);
    fn_801E8034(fn_80023CA8);
    fn_801F0C20(fn_80023DD4);
}
