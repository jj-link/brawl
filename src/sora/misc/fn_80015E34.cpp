#pragma force_active on
struct Ent { int w; int a; int b; int c; };
struct Node { unsigned short id; unsigned short count; Node* next; Ent ents[1]; };

static inline bool match(Ent* e, unsigned a, int b, unsigned c) {
    unsigned char* p = (unsigned char*)e;
    if (p[1] == a && (e->w >> 24) == b && *(unsigned short*)(p + 2) == c) return true;
    return false;
}

static inline Ent* findEnt(Node* n, unsigned a, int b, unsigned c) {
    Ent* e = n->ents;
    Ent* r = 0;
    for (int i = 0; i < n->count; i++, e++) {
        if (match(e, a, b, c)) { r = e; break; }
    }
    return r;
}

struct Owner { char pad[0x68]; Node* head; };

extern "C" int fn_80015E34(Owner* o, unsigned a, int b, int c, int* out, unsigned id) {
    Node* n = o->head;
    if (id == 0xfffe) {
        while (n) {
            Ent* e = findEnt(n, a, b, (unsigned short)c);
            if (e) { *out = e->c; return e->b; }
            n = n->next;
        }
    } else {
        while (n) {
            if (id == n->id) {
                Ent* e = findEnt(n, a, b, (unsigned short)c);
                if (e) { *out = e->c; return e->b; }
            }
            n = n->next;
        }
    }
    return 0;
}
