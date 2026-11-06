#pragma force_active on
extern "C" int fn_8007A314(int, int);
extern "C" int fn_801CA274(void*, unsigned int, int, int);
extern "C" void fn_8007A78C(char*, int, int);

struct Obj {
    char pad[0x2d0];
    char* member;
};

extern "C" void fn_80073D24(Obj* self, int a, int b) {
    fn_801CA274((char*)self + 0x18c, a, fn_8007A314((int)self->member, b), 0x10000);
    fn_8007A78C(self->member, a, b);
}
