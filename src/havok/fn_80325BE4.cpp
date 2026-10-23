#pragma force_active on
extern "C" {

extern char lbl_80488CB8[];

struct S {
    void* p;
    char _4[2];
    short f;
    char _8[0x132];
} __attribute__((aligned(16)));

void* fn_80325BE4() {
    S s;
    if (&s.p != 0) {
        s.f = 1;
        s.p = lbl_80488CB8;
    }
    return s.p;
}

}
