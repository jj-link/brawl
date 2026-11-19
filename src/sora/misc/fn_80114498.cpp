#include <types.h>
#pragma force_active on

struct Node {
    char pad[12];
    short index;
};
struct Ground {
    short pad;
    unsigned short count;
};
struct Entry {
    Node* node;
    Ground* ground;
    void* owner;
    unsigned char type;
    unsigned char flag : 1;
    unsigned char rest : 7;
    Entry() : node(0), ground(0), owner(0), type(0), flag(0) {}
};

extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" Node* fn_80111B70(void*, Node*);

inline bool sameGround(const Entry& a, const Entry& b) { return a.ground == b.ground; }

extern "C" int fn_80114498(const Entry& self, const Entry& other) {
    Entry out = self;
    Entry next;
    int ret = 0;
    if (self.ground == other.ground) {
        int n = self.ground->count;
        while (n != 0) {
            int found = 0;
            if (out.node->index >= 0)
                found = fn_80113D0C(out, next);
            if (!found) {
                Node* node = fn_80111B70(out.owner, out.node);
                if (node) {
                    next.node = node;
                    next.ground = out.ground;
                    next.owner = out.owner;
                    found = 1;
                } else {
                    next = Entry();
                }
            }
            if (!found)
                break;
            int valid = next.node && next.ground && next.owner;
            if (!valid)
                break;
            if (!sameGround(self, next))
                break;
            if (self.node == next.node)
                break;
            if (next.node == other.node) {
                ret = 1;
                break;
            }
            n--;
            out = next;
        }
    }
    return ret;
}
