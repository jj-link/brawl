#pragma force_active on
extern "C" {
extern char lbl_804666D8[];
struct Vec { float x, y, z; };
extern Vec lbl_8040AF30;
extern const float lbl_805A3518;
int fn_80203640(void*);
void fn_8020385C(void*);
void fn_801BBC1C(void*, int*, int*);
void fn_801BBC68(void*, int, int);
struct Block { char pad[28]; char* end; };
struct Obj {
    void* vtable;
    int a, b;
    unsigned char flag;
    Block* block;
    int c;
    Vec vec;
    char pad[0x40];
    unsigned int x1, x2, x3, y1, y2, y3, z1, z2, z3;
};
void* fn_801BFF68(Obj* self) {
    self->a = 0;
    self->b = 0;
    self->vtable = lbl_804666D8;
    self->flag = 0;
    self->block = 0;
    self->c = 0;
    Vec v = lbl_8040AF30;
    self->vec.x = v.x;
    self->vec.y = v.y;
    self->vec.z = v.z;
    unsigned int x = (unsigned int)self->vec.x;
    unsigned int xc = x > 5000 ? 5000 : (x < 1 ? 1 : x);
    self->x1 = self->x2 = self->x3 = xc;
    unsigned int y = (unsigned int)(lbl_805A3518 * v.y);
    unsigned int yc = y > 99 ? 99 : y;
    self->y1 = self->y2 = self->y3 = yc;
    unsigned int z = (unsigned int)(lbl_805A3518 * v.z);
    unsigned int zc = z > 100 ? 100 : z;
    self->z1 = self->z2 = self->z3 = zc;
    if (self->flag) {
        unsigned int size = (fn_80203640(self->pad) + 0x87) & ~31;
        Block* b = self->block;
        unsigned int available;
        if (b == 0) available = 0;
        else available = b->end - (char*)b;
        if (size <= available) {
            int b, a;
            fn_801BBC1C(&self->flag, &a, &b);
            fn_8020385C(self->pad);
            fn_801BBC68(&self->flag, a, b);
        }
    }
    return self;
}
}