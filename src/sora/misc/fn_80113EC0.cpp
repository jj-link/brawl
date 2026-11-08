#pragma force_active on
struct Node {
    char pad[10];
    short index;
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
extern "C" int fn_80113C20(const Entry&, Entry&);
extern "C" Node* fn_80111B94(void*, Node*);
extern "C" int fn_80113EC0(const Entry& self, Entry& out) {
    int found = 0;
    if (self.node->index >= 0) {
        found = fn_80113C20(self, out);
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
    return found;
}