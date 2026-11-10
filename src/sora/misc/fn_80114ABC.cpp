#pragma force_active on
struct Node {
    char pad[10];
    short prev;
    short next;
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
struct Vec2 { float x, y; };
static inline Vec2 operator-(const Vec2& a, const Vec2& o) { Vec2 r; r.x = a.x - o.x; r.y = a.y - o.y; return r; }
static inline float lengthSq(Vec2 v) { return v.x * v.x + v.y * v.y; }
struct Seg { Vec2 a; Vec2 b; };
extern "C" void getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(void*, Seg*, Node*);
extern "C" int fn_80113C20(const Entry&, Entry&);
extern "C" int fn_80113D0C(const Entry&, Entry&);
extern "C" Node* fn_80111B70(void*, Node*);
extern "C" Node* fn_80111B94(void*, Node*);
extern "C" int fn_80114ABC(const Entry& self, const Vec2& p, Entry& out) {
    Seg seg;
    getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(self.owner, &seg, self.node);
    float la = lengthSq(seg.a - p);
    float lb = lengthSq(seg.b - p);
    int found;
    if (la < lb) {
        found = 0;
        if (self.node->prev >= 0) found = fn_80113C20(self, out);
        if (!found) {
            Node* n = fn_80111B94(self.owner, self.node);
            if (n) { out.set(n, self.owner, self.value); found = 1; }
            else out = Entry();
        }
    } else {
        found = 0;
        if (self.node->next >= 0) found = fn_80113D0C(self, out);
        if (!found) {
            Node* n = fn_80111B70(self.owner, self.node);
            if (n) { out.set(n, self.owner, self.value); found = 1; }
            else out = Entry();
        }
    }
    return found;
}
