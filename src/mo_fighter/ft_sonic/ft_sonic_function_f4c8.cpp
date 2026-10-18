#pragma force_active on
extern "C" {

typedef struct SonicF4C8
{
    int field0;
    float field1;
    float field2;
    unsigned char field3;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
} SonicF4C8;

void fn_123_F4C8(SonicF4C8 *self, int a, float b, float c,
                 unsigned char d, unsigned char e, unsigned char f, unsigned char g)
{
    self->field0 = a;
    self->field1 = b;
    self->field2 = c;
    self->field3 = d;
    self->field4 = e;
    self->field5 = f;
    self->field6 = g;
}

}
