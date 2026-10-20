#pragma force_active on
struct Vec3f {
    float x, y, z;
};

class ecMgr {
public:
    void setPos(unsigned long, Vec3f*);
};

extern ecMgr* g_ecMgr;

struct Entry {
    unsigned char pad[8];
    unsigned long handle;
    int active;
    unsigned char rest[0x18];
};

struct Object {
    unsigned char pad[0xB0];
    Entry* entries;
};

extern "C" void fn_27_26D2F0(Object* self, int index, const Vec3f* pos) {
    if (self->entries[index].active != 0) {
        Vec3f copy = *pos;
        g_ecMgr->setPos(self->entries[index].handle, &copy);
    }
}
