#pragma force_active on
typedef unsigned short u16;

struct Obj {
    char pad[0x50];
    void* m_50;
    short m_54;
    short m_56;
};

struct Model {
    char pad[0xe8];
    void* unkE8;
};

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);
extern "C" void fn_80062B78(char* self);

extern "C" void fn_80062A98(Obj* self, Model* arg1, const char* name, int flag) {
    void* resource = arg1->unkE8;
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&resource, name);
    u16 value;
    if (node != 0) {
        int v;
        if (node != 0) {
            v = *(int*)((char*)node + 0xc);
        } else {
            v = 0;
        }
        value = (u16)v;
    } else {
        value = 0;
    }
    self->m_50 = arg1;
    if (arg1) {
        u16 f = self->m_56;
        self->m_54 = value;
        f &= 0xFFFE;
        self->m_56 = f;
        if (flag) {
            f |= 1;
            self->m_56 = f;
        }
        fn_80062B78((char*)self);
    }
}
