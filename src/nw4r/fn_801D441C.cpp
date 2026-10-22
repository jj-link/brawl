#pragma force_active on
extern "C" char* fn_801CC2E4();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801D1210(void*, unsigned int);

struct Inner {
    char pad[0x31];
    unsigned char unk31;
    unsigned char unk32;
    char pad2[0xDC - 0x33];
    void* unkDC;
};

struct Obj {
    char pad[0x8E];
    bool unk8E;
    char pad2[0xD4 - 0x8F];
    Inner* unkD4;
};

extern "C" void fn_801D441C(Obj* o, unsigned int v) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    int f = 0;
    Inner* m = o->unkD4;
    o->unk8E = ((unsigned char)v != 0);
    if (m != 0 && m->unk32 != 0) f = 1;
    if (f) {
        Inner* n = o->unkD4;
        if (v != (n->unk31 != 0)) {
            n->unk31 = v;
            fn_801D1210(n->unkDC, v);
        }
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
