#pragma force_active on
#pragma fp_contract on
typedef unsigned char u8;
struct Byte { u8 x; };
struct Vec { float v[4]; } __attribute__((aligned(16)));
struct Data { char v[0x40]; } __attribute__((aligned(16)));
struct Entry { char data[0x30]; };
struct List { Entry* entries; };
struct Obj { char pad[0x10]; List* list; char pad2[0x6c]; Vec vec; };
struct Arg { char pad[0x21]; u8 count; u8 pad2; u8 flag; char pad3[0xc]; char value[1]; };
extern float lbl_805A45F8;
extern "C" {
void fn_803063A4(Obj*);
void fn_8030665C(Obj*, Arg*);
Byte fn_80306DA0(Obj*, Arg*);
void fn_80305AD4(u8*, u8*);
unsigned int fn_802A0BD8(u8*);
Byte fn_80306EF0(Arg*);
float fn_80294878(void*);
float fn_802A0C4C(float, float);
float* fn_80297488(void*, int);
void fn_802DB598(void*);
void fn_80305A54(void*, float);
int fn_80303F84(Obj*, void*);
void fn_80303F78(int*);
void fn_80303700(void*);
int fn_80304DEC(Obj*, Arg*, int*, void*);
void* fn_802915BC(void*, int);
void fn_80306EFC(Obj*, void*, int*, void*, void*);
void fn_80306FAC(Obj*, Arg*);
int fn_80303704(Obj*, Arg*, void*, int*);
void fn_80307260(Obj*, Arg*, int*);
}
extern "C" void fn_80306424(Obj* self, Arg* arg) {
    int skip;
    int x;
    int copy;
    u8 b;
    Byte a;
    Byte c;
    u8 tmp;
    fn_803063A4(self);
    Entry* entries = self->list->entries;
    fn_8030665C(self, arg);
    a = fn_80306DA0(self, arg);
    fn_80305AD4(&b, &a.x);
    skip = 0;
    if (!fn_802A0BD8(&b)) {
        c = fn_80306EF0(arg);
        if (fn_802A0BD8(&c.x))
            skip = 1;
    }
    if (!skip) {
        int result;
        if (arg->count) {
            float f = fn_80294878(entries);
            int i = arg->count - 1;
            while (i > 0) {
                f = fn_802A0C4C(f, fn_80294878(&entries[i]));
                --i;
            }
            f = f - lbl_805A45F8 * *fn_80297488(&self->vec, 0);
            Vec v;
            fn_802DB598(&v);
            fn_80305A54(&v, f);
            result = fn_80303F84(self, &v);
        } else {
            result = fn_80303F84(self, &self->vec);
        }
        if (!result) {
            Data d;
            fn_80303F78(&x);
            fn_80303700(&d);
            int status = fn_80304DEC(self, arg, &x, &d);
            if (fn_802A0BD8(&b) && status) {
                fn_80306EFC(self, arg->value, &x, &d, fn_802915BC(&tmp, status == 2));
                if (fn_802A0BD8(&arg->flag))
                    fn_80306FAC(self, arg);
            }
            if (status == 2 && !fn_80303704(self, arg, &d, &x)) {
                copy = x;
                fn_80307260(self, arg, &copy);
            }
        }
    }
}
