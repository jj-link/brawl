#pragma force_active on
struct StObj {
    unsigned char pad[0x184];
    unsigned char a;
    int b;
    float c;
};

extern "C" void fn_76_8D8(StObj* p, unsigned char a, int b, float c) {
    p->a = a;
    p->b = b;
    p->c = c;
}
