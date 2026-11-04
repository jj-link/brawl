#include <types.h>
#pragma force_active on

extern float randf();

struct Entry {
    int value;
    char pad[8];
};

struct Params {
    char pad[0x120];
    Entry entries[13];
};

struct OutEntry {
    int value;
    char pad[0x24];
};

struct Out {
    char pad[0x84];
    OutEntry entries[8];
};

struct Inner {
    char pad[0xA8];
    Out* out;
};

struct Object {
    char pad[0xCC];
    Inner* inner;
    char pad2[0x80];
    Params* params;
};

extern "C" void fn_27_272A1C(Object* self, u32 n) {
    if (n >= 1) {
        float f = randf();
        int i = 0;
        int j = 0;
        int x;
        unsigned int r;

        for (int k = (r = (int)((float)n * f) % (long)n, 0);
             k != 5; k++, i += 12, j += 40) {
            int v = *(int*)((char*)self->params + 0x120 + i);
            if (v > 0) {
                Inner* p = self->inner;
                x = r + v;
                if (x > 0) {
                    *(int*)((char*)p->out + 0x84 + j) = x;
                }
            }
        }

        int v = self->params->entries[10].value;
        if (v > 0) {
            int x = r + v;
            Inner* p = self->inner;
            if (x > 0) {
                p->out->entries[5].value = x;
            }
        }

        v = self->params->entries[11].value;
        if (v > 0) {
            int x = r + v;
            Inner* p = self->inner;
            if (x > 0) {
                p->out->entries[6].value = x;
            }
        }

        v = self->params->entries[12].value;
        if (v > 0) {
            int x = r + v;
            Inner* p = self->inner;
            if (x > 0) {
                p->out->entries[7].value = x;
            }
        }
    }
}
