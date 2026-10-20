#pragma force_active on
struct FloatBlock {
    unsigned int pad[3];
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
};

extern "C" {
void fn_27_253B4(FloatBlock* p) {
    p->d = p->a;
    p->e = p->b;
    p->f = p->c;
}
}
