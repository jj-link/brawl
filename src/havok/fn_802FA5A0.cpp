#pragma force_active on
#pragma use_lmw_stmw on

struct Elem {
    char pad[4];
    unsigned short f4;
    short f6;
};

struct Entry {
    Elem* item;
    char pad[0x20];
};

struct List {
    Elem** data;
    int size;
    unsigned int raw;
};

struct Ctx {
    char pad0[8];
    void* p8;
    char pad1[0x60];
    Entry* p6c;
    int n70;
    int pad2;
    Elem** p78;
    int n7c;
};

extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_802F8F98(void*, void*, int);

extern "C" void fn_802FA5A0(Ctx* arg0, List* arg1) {
    void* context = arg0->p8;

    for (int i = arg0->n70 - 1; i >= 0; --i) {
        Elem* e = arg0->p6c[i].item;
        if (e->f4 != 0)
            ++e->f6;
        fn_802F8F98(context, e, 0);
        if (arg1->size == (int)(arg1->raw & 0x3fffffff))
            fn_8027CE3C(arg1, 4);
        arg1->data[arg1->size++] = e;
    }

    for (int i = arg0->n7c - 1; i >= 0; --i) {
        Elem* e = arg0->p78[i];
        if (e->f4 != 0)
            ++e->f6;
        fn_802F8F98(context, e, 0);
        if (arg1->size == (int)(arg1->raw & 0x3fffffff))
            fn_8027CE3C(arg1, 4);
        arg1->data[arg1->size++] = e;
    }
}
