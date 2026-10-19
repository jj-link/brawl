#pragma force_active on
struct ftOwner;
extern "C" {
    extern ftOwner* g_ftManager;
    int fn_27_23AC10(void* self);
    void fn_27_10A128(void* owner, unsigned long entityId, unsigned long id);
}

struct fn27Obj {
    char pad[0x4c];
    unsigned long m_entityId;
};

extern "C" void fn_27_23E65C(fn27Obj* self) {
    if (fn_27_23AC10(self)) {
        fn_27_10A128(g_ftManager, self->m_entityId, 1);
    }
}
