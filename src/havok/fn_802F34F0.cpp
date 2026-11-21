#pragma force_active on
#pragma use_lmw_stmw on
extern "C" int __cntlzw(unsigned int);
struct Input { char pad[0x10]; int offset; };
struct Data { char pad[0x20]; unsigned short id; char pad2[0x26]; };
struct Part { char pad[0x08]; unsigned char* owner; char pad2[0x4c]; Data* data; signed char kind; char pad3[0x4b]; unsigned char type; };
struct Context;
class Class_804886B0 {
public:
    virtual void fn_802EB0E8();
    virtual void fn_80080A64();
    virtual int fn_802F343C(Input*, Input*, Context*, int);
};
struct Row { char pad[0x0c]; Class_804886B0* entries[5]; };
struct Context { Row* rows; };
extern "C" void fn_802F9A04(unsigned char*, Part*, Part*);
extern "C" void fn_802FEDA0(Input*, Input*, Context*, int*, int*);
extern "C" void fn_802FEEBC(void*, Input*, Input*, int, Context*, int);
inline Data* choose(Data* d, Data* e) {
    if (!(signed char)((unsigned int)__cntlzw(d->id ^ 0xffff) >> 5)) return d;
    if (!(signed char)((unsigned int)__cntlzw(e->id ^ 0xffff) >> 5)) d = e;
    return d;
}
extern "C" void fn_802F34F0(Input* a, Input* b, Context* ctx) {
    Part* x = (Part*)((char*)a + a->offset);
    Part* y = (Part*)((char*)b + b->offset);
    int different = 0;
    int valid = 0;
    if (!(signed char)((unsigned int)__cntlzw(x->type - 7) >> 5) &&
        !(signed char)((unsigned int)__cntlzw(y->type - 7) >> 5)) valid = 1;
    if (valid && x->data != y->data) different = 1;
    if (different) fn_802F9A04(x->owner, x, y);
    Data* d = x->data;
    Data* e = y->data;
    d = choose(d, e);
    int result;
    int swap;
    fn_802FEDA0(a, b, ctx, &result, &swap);
    if (swap) { Input* tmp = a; a = b; b = tmp; }
    int k = y->kind;
    fn_802FEEBC((char*)d + 0x48, a, b, result, ctx,
        ctx->rows[x->kind].entries[k]->fn_802F343C(a, b, ctx, k));
}