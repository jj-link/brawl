#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void fn_80086610(void*, void*);
extern "C" void* fn_80081CE8(void*, int);
extern "C" void* fn_8009B324(void*);
extern "C" void fn_8009B8FC(void*);
extern "C" void fn_8009B950(void*);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_8049DEC8[3];
extern void* lbl_805A0EC8;
struct Mgr { char pad[0x58]; void* f58; };
struct Obj { char pad[0x1fc]; void** data; int size; };
struct Array {
    void** data; int size; unsigned int raw;
    unsigned int rawValue() const { return raw; }
};
struct Self { Array a; char pad1[0xcc - sizeof(Array)]; Array b; Array c; };
struct Reg {
    void** data; int size; unsigned int raw;
    int sizeValue() const { return size; }
    unsigned int rawValue() const { return raw; }
};
extern "C" Self* fn_8008B00C(Self* self, int flag) {
    if (self) {
        Obj* obj; int j; int off; int joff; int i;
        off = 0;
        void* x = ((Mgr*)lbl_8049DEC8[0])->f58;
        void* t = x ? x : 0;
        if (t) { fn_80086610(t, self); }
        i = 0;
        off = 0;
        while (i < self->a.size) {
            obj = *(Obj**)((char*)self->a.data + off);
            if (obj) {
                j = 0; joff = 0;
                while (j < obj->size) {
                    void* p = *(void**)((char*)obj->data + joff);
                    if (p) {
                        if (p) { __dl__FPv(p); }
                        *(void**)((char*)obj->data + joff) = 0;
                    }
                    joff += 4; j++;
                }
            }
            fn_80081CE8(*(void**)((char*)self->a.data + off), 1);
            i++;
            *(void**)((char*)self->a.data + off) = 0;
            off += 4;
        }
        if (!(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 2, 0x15);
        }
        self->b.data = 0; self->b.size = 0;
        self->b.raw = (self->b.raw & 0x40000000) | 0x80000000;
        if (!(self->c.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->c.data, self->c.rawValue() & 0x3fffffff, 0x15);
        }
        self->c.data = 0; self->c.size = 0;
        self->c.raw = (self->c.raw & 0x40000000) | 0x80000000;
        if (!(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.rawValue() << 2, 0x15);
        }
        self->a.data = 0; self->a.size = 0;
        self->a.raw = (self->a.raw & 0x40000000) | 0x80000000;
        Reg* reg = (Reg*)fn_8009B324(lbl_8049DEC8[0]);
        int index = 0;
        int byteOffset = 0;
        for (int j = 0; j < reg->size; j++, index++) {
            if (*(void**)((char*)reg->data + byteOffset) == (void*)self) {
                if (reg->sizeValue() == 1) {
                    if (!(reg->raw & 0x80000000)) {
                        fn_8027EABC(lbl_805A0EC8, reg->data, reg->rawValue() << 2, 0x15);
                    }
                    reg->data = 0; reg->size = 0;
                    reg->raw = (reg->raw & 0x40000000) | 0x80000000;
                } else {
                    reg->size--;
                    reg->data[index] = reg->data[reg->size];
                }
                break;
            }
            byteOffset += 4;
        }
        fn_8009B8FC(lbl_8049DEC8[0]);
        fn_8009B950(lbl_8049DEC8[0]);
        if ((unsigned int)self + 0xd8 != 0 && !(self->c.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->c.data, self->c.rawValue() & 0x3fffffff, 0x15);
        }
        if ((unsigned int)self + 0xcc != 0 && !(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 2, 0x15);
        }
        if (self != 0 && !(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.rawValue() << 2, 0x15);
        }
        if (flag > 0) { __dl__FPv(self); }
    }
    return self;
}