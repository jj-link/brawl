#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);
extern "C" void setEnableCollisionStatus__6GroundFb(void* self, bool enable);
extern "C" void fn_62_33C4(void* self, float deltaFrame);

extern "C" void fn_62_33C4(void* self, float deltaFrame) {
    struct Self {
        unsigned char pad0[0x6C];
        unsigned char unk6C;
        unsigned char pad6D[0xC8 - 0x6D];
        unsigned char unkC8;
        unsigned char padC9[0x160 - 0xC9];
        unsigned char* ptr160;
    };
    Self* s = (Self*)self;
    update__9grGimmickFf(self, deltaFrame);
    if (s->unkC8 != 0) {
        unsigned char v = *s->ptr160;
        switch (v) {
            case 1:
                if (((s->unk6C >> 5) & 1) == 1u)
                    setEnableCollisionStatus__6GroundFb(self, false);
                break;
            case 2:
                if (((s->unk6C >> 5) & 1) == 0u)
                    setEnableCollisionStatus__6GroundFb(self, true);
                break;
            case 3:
                if (((s->unk6C >> 5) & 1) == 1u)
                    setEnableCollisionStatus__6GroundFb(self, false);
                break;
            case 4:
                if (((s->unk6C >> 5) & 1) == 1u)
                    setEnableCollisionStatus__6GroundFb(self, false);
                break;
        }
    }
}