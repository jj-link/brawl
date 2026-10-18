#pragma force_active on
extern "C" void __dla__FPv(void*);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_262430();
extern "C" void* __construct_new_array(
    void*, void (*)(), void*, unsigned long, int);
extern "C" void setIdentity__6MatrixFv(void*);

extern const float lbl_27_rodata_4388;
extern const float lbl_27_rodata_4398;

struct Data {
    float a, b, c, d, e, f, g, h, i;
    float j, k, l, m, n, o, p, q, r;

    Data()
        : a(lbl_27_rodata_4388),
          b(lbl_27_rodata_4388),
          c(lbl_27_rodata_4388),
          d(lbl_27_rodata_4388),
          e(lbl_27_rodata_4388),
          f(lbl_27_rodata_4388),
          g(lbl_27_rodata_4398),
          h(lbl_27_rodata_4398),
          i(lbl_27_rodata_4398),
          j(lbl_27_rodata_4388),
          k(lbl_27_rodata_4388),
          l(lbl_27_rodata_4388),
          m(lbl_27_rodata_4388),
          n(lbl_27_rodata_4388),
          o(lbl_27_rodata_4388),
          p(lbl_27_rodata_4398),
          q(lbl_27_rodata_4398),
          r(lbl_27_rodata_4398) {}
};

struct Callback {
    int a, b;
    Data data;
    char matrix[48];
};

struct Gimmick {
    char pad[0xD4];
    Callback* callbacks;
    unsigned long count;
    int used;
};

extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(
    Gimmick* self, unsigned long count, int heap)
{
    if (self->callbacks) {
        if (self->callbacks)
            __dla__FPv((char*)self->callbacks - 16);
    }

    self->callbacks = 0;
    self->count = count;
    self->used = 0;
    self->callbacks = (Callback*)__construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(count * 128 + 16, heap),
        fn_27_262430, 0, 128, count);

    for (int i = 0; i < (int)count; i++) {
        Callback* cb = &self->callbacks[i];
        cb->a = 0;
        cb->b = 0;
        cb->data = Data();
        setIdentity__6MatrixFv(cb->matrix);
    }
}
