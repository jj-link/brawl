#pragma force_active on
typedef struct {
    unsigned char a;
    unsigned char pad;
    unsigned short b;
} FnStruct;

void fn_8024FCC0(FnStruct* s) {
    s->a = 0;
    s->b = 0;
}
