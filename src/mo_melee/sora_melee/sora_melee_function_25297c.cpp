#pragma force_active on
struct Object {
    char pad[0x284];
    int count;
};

extern "C" void fn_27_249B14(Object*, int, int, int);

extern "C" int fn_27_25297C(Object* self, int a, int b, int c) {
    ++self->count;
    fn_27_249B14(self, a, b, c);
    return 0;
}
