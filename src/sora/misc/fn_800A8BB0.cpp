#pragma force_active on
struct Pair { unsigned int x, y; };
struct Result {
    unsigned char a;
    Pair b, c;
};
struct Object {
    char pad[0x14];
    Result result;
};
extern "C" Result fn_800A8DB4(Object*, int, int);
extern "C" void fn_800A8BB0(Object* self, int a, int b) {
    self->result = fn_800A8DB4(self, a, b);
}
