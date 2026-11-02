#include <types.h>
#pragma force_active on

struct Node {
    u8 pad[0xA];
    s16 index;
    u16 fieldC;
    u16 : 12;
    u16 flags : 4;
};

struct Entry {
    Node* node;
    int value;
    void* owner;
    u8 fieldC;
    u8 flag : 1;
    u8 rest : 7;
    void set(Node* n, void* o, int v) { node = n; value = v; owner = o; }
    Entry() {
        node = 0;
        value = 0;
        owner = 0;
        fieldC = 0;
        flag = 0;
    }
};

extern "C" int fn_80113C20(Entry*, Entry*);
extern "C" Node* fn_80111B94(void*, Node*);

extern "C" int fn_801140C0(const Entry& self, Entry& out) {
    int found = 0;
    int result = 0;
    if (self.node->index >= 0) {
        found = fn_80113C20((Entry*)&self, &out);
    }
    if (!found) {
        Node* node = fn_80111B94(self.owner, self.node);
        if (node) {
            found = 1;
            out.set(node, self.owner, self.value);
        } else {
            out = Entry();
        }
    }
    if (found && (self.node->flags & out.node->flags)) {
        result = 1;
    }
    return result;
}
