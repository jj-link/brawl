#include <gr/collision/gr_collision.h>
#include <types.h>
#pragma force_active on

struct GroundData { u8 pad[0x54]; u8 flags; };
struct Entry {
    grCollisionLine* line;
    GroundData* ground;
    grCollision* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;
    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    bool valid() const { return line && ground && collision; }
    bool enabled() const {
        return valid() && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1);
    }
};
extern "C" int fn_80113C20(const Entry&, Entry&);
extern "C" grCollisionLine* fn_80111B94(grCollision*, grCollisionLine*);
inline int matchLines(grCollisionLine* a, grCollisionLine* b) {
    int result = 0;
    if (*(u16*)((char*)a + 0xe) & *(u16*)((char*)b + 0xe) & 0xf)
        result = 1;
    return result;
}
extern "C" int fn_80114670(const Entry& self, const Entry& target) {
    Entry cur = self;
    int result = 0;
    Entry next;
    int counter = 10;
    do {
        int found = 0;
        if (*(s16*)((char*)cur.line + 0xa) >= 0)
            found = fn_80113C20(cur, next);
        if (!found) {
            grCollisionLine* line = fn_80111B94(cur.collision, cur.line);
            if (line) {
                next.line = line;
                next.ground = cur.ground;
                next.collision = cur.collision;
            } else {
                next = Entry();
            }
        }
        int enabled;
        if (next.valid() && ((next.ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
            enabled = 1;
        else
            enabled = 0;
        if (!enabled) break;
        if (!matchLines(next.line, target.line)) break;
        if (next.line == target.line) {
            result = 1;
            break;
        }
        --counter;
        cur = next;
    } while (counter);
    return result;
}