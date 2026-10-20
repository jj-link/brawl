#pragma force_active on
typedef struct {
    unsigned int hi : 6;
    unsigned int lo : 26;
} Hdr;

typedef struct {
    unsigned int pad[2];
    Hdr h;
} Obj;

extern "C" void fn_27_CFB44(Obj *p, unsigned int v) {
    p->h.hi = v;
}
