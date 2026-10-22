#pragma force_active on
struct Node {
    char pad[12];
    short index;
    unsigned short unused : 12;
    unsigned short flags : 4;
};
struct Entry {
    Node* node;
    void* value;
    void* owner;
    unsigned char type;
    unsigned char flag : 1;
    unsigned char rest : 7;
    void set(Node* n, void* o, void* v) { node = n; value = v; owner = o; }
    Entry() : node(0), value(0), owner(0), type(0), flag(0) {}
};
extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" Node* fn_80111B70(void*, Node*);
extern "C" int fn_801141C0(const Entry& self, Entry& out) {
    int found = 0;
    int result = 0;
    if (self.node->index >= 0) {
        found = fn_80113D0C(self, out);
    }
    if (!found) {
        Node* node = fn_80111B70(self.owner, self.node);
        if (node) {
            out.set(node, self.owner, self.value);
            found = 1;
        } else {
            out = Entry();
        }
    }
    if (found && (self.node->flags & out.node->flags)) {
        result = 1;
    }
    return result;
}
