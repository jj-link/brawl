#pragma force_active on
struct Data {
    float x, y, z;
    unsigned char a, b, c, d, e;
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual Data* slot26(int);
};
extern "C" void fn_27_1B7C58(soNullable* self, int source, int destination) {
    Data* src = self->slot26(source);
    Data* dst = self->slot26(destination);
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
}