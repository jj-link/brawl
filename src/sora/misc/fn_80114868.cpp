#include <gr/collision/gr_collision.h>
#include <types.h>
#pragma force_active on
struct GroundData { u8 pad[0x54]; u8 flags; };
struct Entry {
 grCollisionLine* line; GroundData* ground; grCollision* collision; u8 byte;
 u8 flag : 1; u8 rest : 7;
 Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
};
extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" grCollisionLine* fn_80111B70(grCollision*, grCollisionLine*);
inline int overlap(grCollisionLine* a, grCollisionLine* b) {
 int match = 0;
 if (*(u16*)((char*)a + 0xe) & *(u16*)((char*)b + 0xe) & 0xf) match = 1;
 return match;
}
extern "C" int fn_80114868(const Entry& self, const Entry& other) {
 Entry cur = self;
 int result = 0;
 Entry next;
 int count = 10;
 do {
  int found = 0;
  if (*(s16*)((char*)cur.line + 0xc) >= 0) found = fn_80113D0C(cur, next);
  if (!found) {
   grCollisionLine* line = fn_80111B70(cur.collision, cur.line);
   if (line) { next.line = line; next.ground = cur.ground; next.collision = cur.collision; }
   else { next = Entry(); }
  }
  int valid = 0;
  int has = 0;
  if (next.line && next.ground) has = 1;
  if (has && next.collision) valid = 1;
  int enabled;
  if (valid && ((next.ground->flags >> 4) & 1) &&
      ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1)) enabled = 1;
  else enabled = 0;
  if (!enabled) break;
  if (!overlap(next.line, other.line)) break;
  if (next.line == other.line) { result = 1; break; }
  --count;
  cur = next;
 } while (count);
 return result;
}