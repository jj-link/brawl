#include <string.h>
#pragma force_active on
typedef struct Quad { int a, b, c, d; } Quad;
typedef struct Obj {
    char pad0[0xc];
    int state;
    char pad10[0x18];
    Quad quad;
    void *data;
    int length;
    char pad40[0x28];
    char buffer[1];
} Obj;
extern void fn_80378B50(void **, int *);
extern void *fn_8035DFE8(int);
extern void fn_803733BC(void *);
extern char *fn_803734CC(char *, unsigned char *);
extern int fn_803773BC(Obj *, void *);
int fn_8037424C(Obj *self, void *data, int length, Quad *quad) {
    unsigned char buf[0x20];
    int size;
    void *src;
    src = data;
    size = length;
    fn_80378B50(&src, &size);
    if (size > 0) {
        self->data = fn_8035DFE8(size);
        if (self->data == 0) return 1;
        memcpy(self->data, src, size);
        self->length = size;
    }
    if (quad != 0) self->quad = *quad;
    fn_803733BC(buf);
    fn_803734CC(self->buffer, buf);
    fn_803773BC(self, buf);
    self->state = 0;
    return 0;
}