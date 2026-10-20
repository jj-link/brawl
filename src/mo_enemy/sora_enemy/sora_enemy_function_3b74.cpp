#pragma force_active on
typedef unsigned long u32;

struct Holder {
    char pad[0x10];
    u32 unk10;
};

class emResourceModuleImpl {
public:
    void* getInfoTexFile(u32 a, u32 b);
};

class Enemy {
public:
    void* getFaceTexPtr(u32 p);

    char pad0[0x91c];
    Holder* unk91c;
    char pad1[0x938 - 0x920];
    emResourceModuleImpl unk938;
};

void* Enemy::getFaceTexPtr(u32 p) {
    return unk938.getInfoTexFile(unk91c->unk10, p);
}
