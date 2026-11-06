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

extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" grCollisionLine* fn_80111B70(grCollision*, grCollisionLine*);

extern "C" int fn_80116B1C(const Entry& self, Entry& out) {
    clSegment2D segment;
    self.collision->getSegment(&segment, self.line);
    Entry next;
    Entry* np = &next;
    out = self;
    while (true) {
        int found = 0;
        if (*(s16*)((char*)out.line + 0xc) >= 0)
            found = fn_80113D0C(out, next);
        if (!found) {
            grCollisionLine* line = fn_80111B70(out.collision, out.line);
            if (line) {
                next.line = line;
                next.ground = out.ground;
                next.collision = out.collision;
            } else {
                next = Entry();
            }
        }
        int valid = 0;
        if (next.line && next.ground && next.collision)
            valid = 1;
        int enabled;
        if (valid && ((next.ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
            enabled = 1;
        else
            enabled = 0;
        if (enabled == 0)
            break;
        if (!((*(u8*)((char*)np->line + 0xf) >> 3) & 1))
            break;
        out = next;
    }
    return 1;
}
