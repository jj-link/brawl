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
    void* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;
    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}
    bool valid() const { return line && ground && collision; }
};

extern "C" void fn_801119F8(void* coll, float* out, void* line);
extern "C" int fn_80113C20(const Entry&, Entry&);
extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" void* fn_80111B94(void*, void*);
extern "C" void* fn_80111B70(void*, void*);

extern "C" int fn_8011557C(const Entry& self, Entry& out, float x) {
    float seg[4];
    Entry next;
    fn_801119F8(self.collision, seg, self.line);
    if (seg[0] <= x && x <= seg[2]) {
        out = self;
        return 1;
    }
    out = self;
    if (seg[2] < x) {
        while (true) {
            int found;
            int ok;
            ok = 0;
            found = 0;
            if (*(s16*)((char*)out.line + 0xc) >= 0)
                found = fn_80113D0C(out, next);
            if (!found) {
                void* line = fn_80111B70(out.collision, out.line);
                if (line) {
                    next.line = line;
                    next.ground = out.ground;
                    next.collision = out.collision;
                    found = 1;
                } else {
                    next = Entry();
                }
            }
            if (found && (((LineFlags*)out.line)->direction & ((LineFlags*)next.line)->direction))
                ok = 1;
            if (!ok)
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
            fn_801119F8(next.collision, seg, next.line);
            if (x <= seg[2]) {
                out = next;
                return 1;
            }
            if (seg[2] <= seg[0])
                break;
            out = next;
        }
    } else if (x < seg[0]) {
        while (true) {
            int found;
            int ok;
            ok = 0;
            found = 0;
            if (*(s16*)((char*)out.line + 0xa) >= 0)
                found = fn_80113C20(out, next);
            if (!found) {
                void* line = fn_80111B94(out.collision, out.line);
                if (line) {
                    next.line = line;
                    next.ground = out.ground;
                    next.collision = out.collision;
                    found = 1;
                } else {
                    next = Entry();
                }
            }
            if (found && (((LineFlags*)out.line)->direction & ((LineFlags*)next.line)->direction))
                ok = 1;
            if (!ok)
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
            fn_801119F8(next.collision, seg, next.line);
            if (seg[0] <= x) {
                out = next;
                return 1;
            }
            if (seg[2] <= seg[0])
                break;
            out = next;
        }
    }
    return 0;
}

