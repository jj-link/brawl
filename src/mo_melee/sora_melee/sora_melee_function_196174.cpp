#pragma force_active on
struct Vec2f {
float m_x,m_y;
Vec2f() {}
void set(float x,float y) { m_x=x; m_y=y; }
Vec2f(float x,float y):m_x(x),m_y(y) {}

friend Vec2f operator-(const Vec2f& a,const Vec2f& b) { return Vec2f(a.m_x-b.m_x,a.m_y-b.m_y); }
friend Vec2f operator+(const Vec2f& a,const Vec2f& b) { return Vec2f(a.m_x+b.m_x,a.m_y+b.m_y); }
friend Vec2f operator*(const Vec2f& a,float b) { return Vec2f(a.m_x*b,a.m_y*b); }
};
struct Line { Vec2f a,b; Line(float x,float y,float z,float w):a(x,y),b(z,w) {} };
struct V3 { float x,y,z; V3() {} V3(const V3& o):x(o.x),y(o.y),z(o.z) {} };
#define F5(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4();
struct ModelBase { char pad[8]; };
struct Model:ModelBase { F5(a) F5(b) F5(c) F5(d) F5(e) F5(f) virtual void g0(); virtual void g1(); virtual void g2(); virtual int index(int); virtual void g4(); virtual void g5(); virtual V3 position(int,int); };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual V3 slot4(); virtual void slot5(); virtual V3 slot6(); };
struct Modules { char pad[4]; Model* model; char pad2[4]; Object_vptr_0* posture; };
struct Object { char pad[0xD8]; Modules* modules; };
extern "C" const float lbl_27_rodata_26E4;
extern "C" void fn_8003DBA8(Vec2f*);
extern "C" int fn_80040F74(const Vec2f*,const Vec2f*,Vec2f*);
extern "C" int fn_27_196174(Object* object,Vec2f* input,Vec2f* output) {
float scale=lbl_27_rodata_26E4;
int index=object->modules->model->index(0x12D);
V3 a=object->modules->model->position(index,0);
V3 b=object->modules->posture->slot4();
V3 c=object->modules->posture->slot6();
Vec2f direction(b.x-c.x,b.y-c.y);
Vec2f delta(a.x-b.x,a.y-b.y);
Vec2f end(c.x+delta.m_x,c.y+delta.m_y);
fn_8003DBA8(&direction);
Line line(end.m_x-direction.m_x*scale,end.m_y-direction.m_y*scale,a.x+direction.m_x*scale,a.y+direction.m_y*scale);
Line bounds(a.x-scale,input->m_y,a.x+scale,input->m_y);
Vec2f result;
if(fn_80040F74(&line.a,&bounds.a,&result)) { output->set(result.m_x,input->m_y); return 1; }
return 0;
}