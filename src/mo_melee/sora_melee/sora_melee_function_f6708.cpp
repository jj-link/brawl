#pragma force_active on
struct Element { int pad; int value; };
class Obj {
public:
 virtual void v0(); virtual void v1(); virtual Element* get(int);
 virtual int size(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
 virtual void v13(); virtual void v14(); virtual void v15(); virtual unsigned int full();
};
class Owner {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual unsigned int s5(); char pad[0xC]; Obj m_obj;
};
extern "C" int fn_27_F6708(Owner* self) {
 if (self->m_obj.full() == 1) return 0x7FFF;
 if (self->s5() == 1) return 0;
 int idx = self->m_obj.size() - 1;
 if (self->m_obj.get(idx)->value < 0x7FFF) {
   idx = self->m_obj.size() - 1;
   return self->m_obj.get(idx)->value + 1;
 }
 int temp;
 int n = self->m_obj.size() - 1;
 while (n >= 0) {
   if (n == 0) {
     if (self->m_obj.get(n)->value == 0) return -1;
     return self->m_obj.get(n)->value - 1;
   }
   temp = self->m_obj.get(n - 1)->value;
   if (self->m_obj.get(n)->value - 1 > temp) return self->m_obj.get(n)->value - 1;
   n--;
 }
 return -1;
}