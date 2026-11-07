#include <gr/collision/gr_collision.h>
#include <types.h>

#pragma force_active on

struct LineFlags {
    u8 pad[14];
    u16 other : 12;
    u16 direction : 4;
};

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

extern "C" int fn_80113C20(const Entry&, Entry&);
extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" grCollisionLine* fn_80111B94(grCollision*, grCollisionLine*);
extern "C" grCollisionLine* fn_80111B70(grCollision*, grCollisionLine*);

extern "C" int fn_801162F4(const Entry& self, Entry& out, float y) {
    clSegment2D segment;
    Entry next;

    self.collision->getSegment(&segment, self.line);
    if (segment.m_p0Pos.m_y <= y && y <= segment.m_p1Pos.m_y) {
        out = self;
        return 1;
    }

    out = self;
    if (segment.m_p1Pos.m_y < y) {
        while (true) {
            int found;
            int compatible = 0;
            found = 0;

            if (*(s16*)((char*)out.line + 0xc) >= 0)
                found = fn_80113D0C(out, next);

            if (!found) {
                grCollisionLine* line = fn_80111B70(out.collision, out.line);
                if (line) {
                    next.line = line;
                    next.ground = out.ground;
                    next.collision = out.collision;
                    found = 1;
                } else {
                    next = Entry();
                }
            }

            if (found && (((LineFlags*)out.line)->direction &
                          ((LineFlags*)next.line)->direction))
                compatible = 1;

            if (!compatible)
                break;

            bool valid = next.valid();
            int enabled;
            if (valid && ((next.ground->flags >> 4) & 1) &&
                ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
                enabled = 1;
            else
                enabled = 0;

            if (!enabled)
                break;

            next.collision->getSegment(&segment, next.line);
            if (y <= segment.m_p1Pos.m_y) {
                out = next;
                return 1;
            }
            if (segment.m_p1Pos.m_y <= segment.m_p0Pos.m_y)
                break;
            out = next;
        }
    } else if (segment.m_p0Pos.m_y > y) {
        while (true) {
            int found;
            int compatible = 0;
            found = 0;

            if (*(s16*)((char*)out.line + 0xa) >= 0)
                found = fn_80113C20(out, next);

            if (!found) {
                grCollisionLine* line = fn_80111B94(out.collision, out.line);
                if (line) {
                    next.line = line;
                    next.ground = out.ground;
                    next.collision = out.collision;
                    found = 1;
                } else {
                    next = Entry();
                }
            }

            if (found && (((LineFlags*)out.line)->direction &
                          ((LineFlags*)next.line)->direction))
                compatible = 1;

            if (!compatible)
                break;

            bool valid = next.valid();
            int enabled;
            if (valid && ((next.ground->flags >> 4) & 1) &&
                ((*(u8*)((char*)next.collision + 0x2c) >> 7) & 1))
                enabled = 1;
            else
                enabled = 0;

            if (!enabled)
                break;

            next.collision->getSegment(&segment, next.line);
            if (segment.m_p0Pos.m_y <= y) {
                out = next;
                return 1;
            }
            if (segment.m_p1Pos.m_x <= segment.m_p0Pos.m_x)
                break;
            out = next;
        }
    }

    return 0;
}
