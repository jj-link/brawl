#pragma force_active on
extern "C" char* strcpy(char*, const char*);
struct Obj {
    int pad0[2];
    int c;
    int b9[9];
    int b2[2];
    int a;
    int b;
    int d;
    int pad44[2];
    int e;
    char name[0x114];
    int x[4];
};
extern "C" void fn_10_1C8F0(Obj* self, int a, int b, int c, int* block9, int* block2, int d, int e, char* name) {
    self->a = a;
    self->b = b;
    self->c = c;
    for (int i = 0; i < 9; i++) self->b9[i] = block9[i];
    self->d = d;
    self->b2[0] = block2[0];
    self->b2[1] = block2[1];
    self->e = e;
    self->x[0] = -1;
    self->x[1] = -1;
    self->x[2] = -1;
    self->x[3] = -1;
    strcpy(self->name, name);
}
