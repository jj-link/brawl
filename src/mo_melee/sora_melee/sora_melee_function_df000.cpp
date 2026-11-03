#pragma force_active on
struct Pair { unsigned int a, b; };
struct Trio { Pair p; unsigned int c; };
struct Data { Trio t[4]; unsigned char a, b; };
class soNullable {
public:
 virtual void isNull();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
 virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
 virtual void slot25(); virtual Data* slot26(int);
};
extern "C" void fn_27_DF000(soNullable* self, int srcIndex, int dstIndex) {
 Data* src = self->slot26(srcIndex);
 Data* dst = self->slot26(dstIndex);
 dst->t[0] = src->t[0];
 dst->t[1] = src->t[1];
 dst->t[2] = src->t[2];
 dst->t[3] = src->t[3];
 dst->a = src->a;
 dst->b = src->b;
}