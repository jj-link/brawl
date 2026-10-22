#pragma force_active on
extern "C" {
extern char lbl_95_data_2550[];
extern char g_ftCommonDataAccesser[];
void* fn_27_148B58(void*, int, unsigned char*);
void fn_95_19A88(void*, int, void*, void*);
}
struct Local9988 {
    unsigned char a, b;
    int c, d, e, f;
    void* g;
    void* h;
};
struct Object9988 { char* table; };
struct Module9988 { char pad[0xc0]; void* field; };
struct Arg9988 { char pad[0xd8]; Module9988* module; };
extern "C" void* fn_95_9988(Object9988* self, Arg9988* arg) {
    self->table = lbl_95_data_2550;
    Local9988 l;
    l.a = 0;
    l.b = 0;
    l.c = 0;
    int kind = l.d = 4;
    void* t = arg->module->field;
    l.e = l.c;
    l.f = l.d;
    l.g = &l.e;
    l.h = t;
    void* r = fn_27_148B58(g_ftCommonDataAccesser, kind, &l.b);
    fn_95_19A88((char*)self + 4, 3, &l.g, r);
    return self;
}
