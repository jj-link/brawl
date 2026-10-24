#pragma force_active on
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct Pad { char p[0x3c]; };
struct Ground : Pad {
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i)
    virtual void x98();
    virtual void startup(void*, int, int);
    virtual void xa0();
    virtual void setData(void*);
    V4(j) V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s) V4(t) V4(u) V4(v) V4(w) V4(y) V4(z) V4(A) V4(B) V4(C)
    virtual void setState(void*);
    virtual void setIndex(int);
    virtual void setFlag(void*);
    virtual void setExtra(void*);
    virtual void setPosition(void*);
};
struct Stage {
    char pad0[0x9C];
    void* data;
    char padA0[0x100];
    void* archive;
    char pad1A4[0x3C];
    char s1E0[2];
    char s1E2[0x7A2];
    char s984[1];
};
extern "C" {
extern char lbl_61_data_0[];
Ground* fn_61_62D0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void createCollision__5StageFP9gfArchiveiP6Ground(Stage*, void*, int, Ground*);
void fn_61_8B8(Stage* self, unsigned int kind) {
    Ground* ground;
    int index;
    int collision;
    char* position;
    char* data = lbl_61_data_0;
    switch (kind) {
    case 2:
        ground = fn_61_62D0(10, data + 0x68, data + 0x7C);
        index = 7;
        position = 0;
        collision = 55;
        break;
    case 4:
        ground = fn_61_62D0(12, data + 0x90, data + 0xA8);
        position = (char*)self + 0x274;
        index = 0;
        collision = 50;
        break;
    case 5:
        ground = fn_61_62D0(13, data + 0xB8, data + 0xD0);
        position = (char*)self + 0x2A4;
        index = 1;
        collision = 51;
        break;
    case 6:
        ground = fn_61_62D0(14, data + 0xE0, data + 0xF8);
        position = (char*)self + 0x2D4;
        index = 2;
        collision = 52;
        break;
    case 7:
        ground = fn_61_62D0(15, data + 0x108, data + 0x120);
        position = (char*)self + 0x304;
        index = 3;
        collision = 53;
        break;
    case 8:
        ground = fn_61_62D0(17, data + 0x130, data + 0x148);
        position = (char*)self + 0x364;
        index = 5;
        collision = 54;
        break;
    case 0:
    case 1:
    case 3:
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(self, ground);
        ground->startup(self->archive, 0, 0);
        ground->setData(self->data);
        ground->setState(self->s1E0);
        ground->setIndex(index);
        ground->setFlag(self->s1E2);
        ground->setExtra(self->s984);
        ground->setPosition(position);
        createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, collision, ground);
    }
}
}
