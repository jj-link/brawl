#pragma force_active on
extern "C" void* fn_8015C1EC(void* self, unsigned short idx);

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
};

struct Entry {
    int unk0;
    Obj* obj;
};

extern "C" void fn_80279274(char* arg0)
{
    unsigned int i;

    for (i = 0; i < *(unsigned short*)(arg0 + 0x10); i++) {
        Entry* e = (Entry*)fn_8015C1EC(arg0 + 8, (unsigned short)i);
        e->obj->slot1();
    }
}
