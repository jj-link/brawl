#pragma force_active on
extern "C" {
void* fn_98_14750(void*);
void* fn_98_14878(void*);
void fn_98_183E4(void*, void*);
}

struct WnPikachu_A { char pad[0x60]; void* b; };
struct WnPikachu_B { char pad[0xd8]; void* c; };
struct WnPikachu_C { char pad[0x1c]; void* m; };

extern "C" void fn_98_140E4(void* owner, int next) {
    void* a = fn_98_14750(owner);
    if (a) {
        void* module = ((WnPikachu_C*)((WnPikachu_B*)((WnPikachu_A*)owner)->b)->c)->m;
        fn_98_183E4(a, module);
    }
    if (next) {
        void* b = fn_98_14878(owner);
        if (b) fn_98_140E4(b, 1);
    }
}
