#pragma force_active on
typedef int s32;
struct Obj {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual int f16();
};
struct Mid { char pad[0x70]; Obj* obj; };
struct Self { char pad[0xD8]; Mid* mid; };
extern "C" bool fn_100_10794(Self* self, s32 arg1) {
    switch (self->mid->obj->f16()) {
    case 0x116:
        if (arg1 == 0x11D) return true;
        break;
    case 0x11D:
        if (arg1 == 0x11E) return true;
        break;
    case 0x11E:
        if (arg1 == 0x11F) return true;
        break;
    case 0x11F:
        if (arg1 == 0x120) return true;
        break;
    case 0x120:
        if (arg1 == 0x121) return true;
        break;
    case 0x121:
        break;
    }
    return false;
}
