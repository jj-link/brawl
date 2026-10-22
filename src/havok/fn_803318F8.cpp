#pragma force_active on

struct Entry {
    int a;
    int b;
};

struct Owner {
    Entry* list;
    char pad[0x8];
    char sub[4];
};

extern "C" int fn_8027D1F0(void* self, int a, int b);
extern "C" int fn_80331B70(Owner* self);
extern "C" void fn_8027D0B8(void* self, int a, int b, Entry* c);

extern "C" void fn_803318F8(Owner* arg0, int arg1, int* arg2) {
    int v;
    int idx;
    Entry* p;

    v = fn_8027D1F0(arg0->sub, arg1, -1);
    idx = fn_80331B70(arg0);
    p = arg0->list + idx;
    p->a = *arg2;
    p->b = v;
    fn_8027D0B8(arg0->sub, arg1, idx, p);
}
