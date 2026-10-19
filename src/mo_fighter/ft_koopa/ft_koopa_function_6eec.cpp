#pragma force_active on
extern "C" {
struct Obj {
    char pad[0x24];
    char sub[0x10];
};
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void*, unsigned char);

void* fn_102_6EEC(Obj* p, short s) {
    fn_27_711E4(p, s, p->sub);
    fn_27_1AB96C(p->sub, 0);
    return p;
}
}
