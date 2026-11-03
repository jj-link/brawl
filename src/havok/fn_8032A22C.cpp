#pragma force_active on
#pragma fp_contract on
extern float lbl_805A4800;
extern "C" void fn_80285A6C(void*, void*);
struct Vec4 { float x,y,z,w; } __attribute__((aligned(16)));
struct Data { Vec4 a,b,c,d,e,f,g,h,i; };
struct Entry { char pad[0xb0]; Data data; };
struct Container { char pad[0x38]; Entry** entries; int count; };
struct Flags { unsigned char* values; };
extern "C" void fn_8032A22C(Container* self, Flags* flags) {
    float zero = lbl_805A4800;
    int offset;
    int i = 0;
    offset = 0;
    for (; i < self->count; ++i, offset += 4) {
        if (flags->values[i] != 1 && flags->values[i] != 2) continue;
        {
            Data* p = &(*(Entry**)((char*)self->entries + offset))->data;
            fn_80285A6C(p, &p->h);
            Vec4 v;
            float nz = p->i.z, ny = p->i.y, nx = p->i.x;
            v.x = nx * p->a.x + ny * p->b.x + nz * p->c.x;
            v.y = nx * p->a.y + ny * p->b.y + nz * p->c.y;
            v.z = nx * p->a.z + ny * p->b.z + nz * p->c.z;
            v.w = zero;
            p->d.x = p->f.x - v.x;
            p->d.y = p->f.y - v.y;
            p->d.z = p->f.z - v.z;
            p->d.w = p->f.w - v.w;
        }
    }
}