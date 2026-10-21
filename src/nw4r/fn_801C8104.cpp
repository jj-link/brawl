#pragma force_active on
extern "C" {
void OSInitMutex(void*);

struct Obj {
    char pad0[0x18];
    int unk18;
    char pad1[0x200];
    int unk21C;
};

void* fn_801C8104(void* p, int v) {
    Obj* o = (Obj*)p;
    o->unk18 = v;
    o->unk21C = 0;
    OSInitMutex(p);
    return p;
}
}
