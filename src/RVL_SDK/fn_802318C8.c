#pragma force_active on
typedef void (*FnPtr)(void);

typedef struct Obj {
    int pad[2];
    FnPtr fn;
} Obj;

extern Obj* lbl_805A0D18;

void fn_802318C8(void) {
    Obj* o = lbl_805A0D18;
    FnPtr f;
    if (o == 0) {
        return;
    }
    f = o->fn;
    if (f == 0) {
        return;
    }
    f();
}
