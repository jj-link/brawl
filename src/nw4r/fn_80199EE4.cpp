#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(unsigned int a, unsigned int b, void* c);
};

struct Obj {
    char pad[0x14];
    unsigned short* bits;
};

struct Helper {
    char pad[0x10];
    unsigned int outerCount;
    unsigned short* outFlags;
    int innerCount;
    Object_vptr_0** objs;
};

extern "C" void fn_8019DA5C(void* self, unsigned int mask, int flag);

extern "C" Object_vptr_0* fn_80199EE4(Helper* arg0, unsigned int arg1) {
    Object_vptr_0* result;
    int found;
    unsigned int i;
    unsigned short val;
    int j;

    result = arg0->objs[arg1];
    if (result != 0) {
        result->slot1(0x10003, 0, arg0);
        arg0->objs[arg1] = 0;
        found = 0;
        for (i = 0; i < arg0->outerCount; i++) {
            val = 0x8000;
            for (j = 0; j < arg0->innerCount; j++) {
                Obj* o = (Obj*)arg0->objs[j];
                if (o != 0 && !(o->bits[i] & 0x8000)) {
                    found = 1;
                    val = 0;
                    break;
                }
            }
            arg0->outFlags[i] = val;
        }
        if (found == 0) {
            fn_8019DA5C(arg0, 4, 0);
        }
    }
    return result;
}
