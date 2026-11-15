#include <gr/collision/gr_collision.h>
#include <types.h>
#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;
    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    bool valid() const { return line && ground && collision; }
};

extern "C" int fn_80113C20(Entry*, Entry*);
extern "C" grCollisionLine* fn_80111B94(grCollision*, grCollisionLine*);

inline bool sameGround(const Entry& a, const Entry& b) { return a.ground == b.ground; }
extern "C" int fn_801142C0(const Entry& self, const Entry& other) {
    int ret;
    Entry cur = self;
    Entry out;
    ret = 0;
    if (self.ground == other.ground) {
        u32 count = *(u16*)((char*)self.ground + 2);
        while (count != 0) {
            int found = 0;
            if (*(s16*)((char*)cur.line + 0xa) >= 0) {
                found = fn_80113C20(&cur, &out);
            }
            if (found == 0) {
                grCollisionLine* line = fn_80111B94(cur.collision, cur.line);
                if (line != 0) {
                    found = 1;
                    out.line = line;
                    out.ground = cur.ground;
                    out.collision = cur.collision;
                } else {
                    out = Entry();
                }
            }
            if (found == 0) break;
            if (!out.valid()) break;
            if (!sameGround(self, out)) break;
            if (self.line == out.line) break;
            if (out.line == other.line) {
                ret = 1;
                break;
            }
            cur = out;
            count--;
        }
    }
    return ret;
}