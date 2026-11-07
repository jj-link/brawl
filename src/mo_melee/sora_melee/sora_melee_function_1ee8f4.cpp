#pragma force_active on
class grCollisionHandle {
public:
    int isValid();
};
extern "C" {
void* fn_80111B70(unsigned, void*);
void* fn_80111B94(unsigned, void*);
}
struct Inner {
    Inner* next;
    unsigned a;
    grCollisionHandle h;
    int pad;
    unsigned c;
    unsigned d;
    unsigned e;
};
struct Ent {
    char pad[0x44];
    Inner* first;
    char pad2[4];
};
struct Obj {
    char pad[0x34c];
    Ent* ents;
    unsigned short count;
};

extern "C" void* fn_27_1EE8F4(Obj* o, unsigned a1, unsigned a2, unsigned a3) {
    Ent* e = o->ents;
    for (int i = 0; i < o->count; i++, e++) {
        for (Inner* n = e->first; n; n = n->next) {
            if (n->h.isValid()) {
                unsigned t = *(unsigned*)&n->h;
                if (t == a1 && n->a == a2) {
                    int f = 0;
                    void* x;
                    for (void* r = (void*)n->c; r; r = x) {
                        if ((unsigned)r == a3) return e;
                        if (!f) {
                            if ((unsigned)r == n->d) {
                                r = (void*)n->c;
                                if ((unsigned)r == n->e) x = 0;
                                else { x = fn_80111B70(t, r); f = 1; }
                            } else x = fn_80111B94(t, r);
                        } else if ((unsigned)r == n->e) x = 0;
                        else x = fn_80111B70(t, r);
                    }
                }
            }
        }
    }
    return 0;
}