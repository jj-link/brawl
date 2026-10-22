#pragma force_active on
extern "C" {
struct Stage;
unsigned getGroundNum__5StageFv(Stage*);
void* getGround__5StageFi(Stage*, int);
int fn_27_260750(void*, void*, void*, void*, void*);

struct E { char p[0x48]; unsigned a:8; unsigned f:8; unsigned c:16; short pad; short s1; unsigned short s2; char q[4]; void* g; };
struct G { char p[0x4c]; void* owner; };
struct S { char p[6]; unsigned short cnt; char q[0x10]; E* ents; };

void fn_27_275628(S* self, Stage* stage, G* other, char* arg3) {
    int off;
    char* src = *(char**)(arg3 + 0x10);
    unsigned n = getGroundNum__5StageFv(stage);
    unsigned i = 0;
    off = 0;
    for (; i < self->cnt; off += 0x60, src += 0x6c, i++) {
        E* e = (E*)((char*)self->ents + off);
        if (*(unsigned char*)(src + 0x4c) != 0) {
            void* p1 = src + 0x2c;
            void* p2 = src + 0x4c;
            if (other == 0) {
                for (unsigned j = 0; j < n; j++) {
                    G* g = (G*)getGround__5StageFi(stage, j);
                    int v;
                    unsigned short w;
                    if (fn_27_260750(g, p1, p2, &v, &w)) {
                        unsigned short ww = w;
                        short vv = v;
                        e->g = g;
                        e->s1 = vv;
                        e->s2 = ww;
                        g->owner = self;
                        e->f = 1;
                        break;
                    }
                }
            } else {
                int v;
                unsigned short w;
                if (fn_27_260750(other, p1, p2, &v, &w)) {
                    unsigned short ww = w;
                    short vv = v;
                    e->g = other;
                    e->s1 = vv;
                    e->s2 = ww;
                    other->owner = self;
                    e->f = 1;
                }
            }
        }
    }
    if (other) other->owner = self;
}
}
