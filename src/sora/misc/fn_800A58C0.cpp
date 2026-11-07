#pragma force_active on
extern "C" const float lbl_805A1F90;
namespace init { extern "C" float lbl_805A1F90; }
struct Vec2 { float x, y; }; struct Vec3 { float x,y,z; };
struct Obj { char pad0[11]; unsigned char flags; char pad1[0x20]; Vec3 a,b,c,d,e; char pad2[0x18]; Vec3 zero; char pad3[0x5c]; float offsetX,offsetY; char pad4[0x20]; Vec3 f,g; };
extern "C" void fn_800A58C0(Obj* p, Vec2* input, int useOffset, float scale) {
 float y=input->y; float x=input->x;
 struct Position { Vec2 xy; float z; } pos={{x,y},init::lbl_805A1F90};
 if(useOffset){pos.xy.x += p->offsetX * scale; pos.xy.y += p->offsetY;}
 Vec3& value=*reinterpret_cast<Vec3*>(&pos);
 p->e=value; p->d=value; p->b=value; p->c=value; p->a=value; p->f=value; p->g=value;
 Vec3 zero={lbl_805A1F90,lbl_805A1F90,lbl_805A1F90}; p->zero=zero; p->flags |= 4;
}