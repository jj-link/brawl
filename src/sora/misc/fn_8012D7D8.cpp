#include <types.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_vector.h>
#include <gr/collision/gr_collision.h>
#pragma force_active on
struct GroundData { u8 pad[0x54]; u8 flags; };
struct Entry {
 grCollisionLine* line; GroundData* ground; grCollision* collision; u8 byte; u8 flag : 1; u8 rest : 7;
 Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
 bool valid() const { return line && ground && collision; }
 int enabled() const { bool ok = valid(); if (ok && ((ground->flags >> 4) & 1) && ((*(u8*)((char*)collision + 0x2c) >> 7) & 1)) return 1; return 0; }
};
struct Segment : clSegment2D { s32 extra; };
struct Self { u8 pad0[0x378]; Vec2f prev0; u8 pad1[0x10]; Vec2f prev1; u8 pad2[0x14]; clRhombus2D rhombus; };
struct Offset : Vec2f { Offset(f32 y, f32 x) : Vec2f(x, y) {} };
extern f32 lbl_805A29C8, lbl_805A29F0, lbl_805A29F4;
extern "C" {
int fn_80113EC0(const Entry&, Entry&, f32*, u8);
void fn_80111968(void*, Segment*, void*, int);
void fn_80115A28(const Entry&, Entry&);
void fn_800429C8(void*, Segment*, Segment*);
int fn_80042FB4(void*, Segment*);
int fn_80042C74(void*, Segment*);
int fn_800408C4(Segment*, Vec2f*, Vec2f*);
void fn_80125250(void*, int, void*, f32);
}
extern "C" void fn_8012D7D8(Self* self, Entry* arg, f32* result) {
 clRhombus2D* rhombus = &self->rhombus;
 int didMove = 0;
 char area[32];
 Entry current;
 Entry found;
 Segment segment;
 Segment previous;
 Segment now;
 Segment other;
 Vec2f intersection;
 Vec2f displacement;
 fn_80113EC0(*arg, current, result, current.rest);
 fn_80111968(arg->collision, &segment, arg->line, 0);
 previous.m_p0Pos = self->prev0;
 previous.m_p1Pos = self->prev1;
 previous.extra = 0;
 now.m_p0Pos = rhombus->m_upPos;
 now.m_p1Pos = rhombus->m_rightPos;
 now.extra = 0;
 bool same0 = false;
 if (previous.m_p0Pos.m_x == now.m_p0Pos.m_x && previous.m_p0Pos.m_y == now.m_p0Pos.m_y) same0 = true;
 if (!same0) {
  int same = 0;
  if (previous.m_p1Pos.m_x == now.m_p1Pos.m_x && previous.m_p1Pos.m_y == now.m_p1Pos.m_y) same = 1;
  if (!same) {
   fn_800429C8(area, &previous, &now);
   if (fn_80042FB4(area, &segment) && fn_80042C74(area, &segment)) {
    didMove = 0;
    Vec2f* endpoint;
    if (now.m_p0Pos.m_x < segment.m_p0Pos.m_x) {
     Vec2f* point;
     if (fn_800408C4(&now, (point = &segment.m_p0Pos), &intersection)) {
      displacement = (*point - intersection) + Offset(lbl_805A29F4, lbl_805A29F0);
      if (displacement.m_y < lbl_805A29F0) didMove = 1;
     }
    } else {
     endpoint = &now.m_p0Pos;
     fn_80111968(current.collision, &other, current.line, 0);
     f32 y = other.m_p0Pos.m_x;
     f32 x = now.m_p0Pos.m_x;
     if (y < x) {
      fn_80115A28(current, found);
      if (found.enabled()) fn_80111968(found.collision, &other, found.line, 0);
     }
     if (now.m_p0Pos.m_x < other.m_p0Pos.m_x && fn_800408C4(&other, (endpoint), &intersection))
      displacement = (intersection - *(endpoint)) + Offset(lbl_805A29F4, lbl_805A29F0);
     else
      displacement = (other.m_p0Pos - *(endpoint)) + Offset(lbl_805A29F4, lbl_805A29F0);
     if (displacement.m_y < lbl_805A29F0) didMove = 1;
    }
    if (didMove) {
     rhombus->move(displacement);
     fn_80125250(self, 5, arg, *result = lbl_805A29C8);
    }
   }
  }
 }
}