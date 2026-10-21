#pragma force_active on
struct Pool {
    void* data;
    short* links;
    short freeHead;
    short count;
    int other[2];
};
extern Pool lbl_27_bss_2BEC;

struct Object {
    int unknown;
    short head;
};

class Slot {
public:
    virtual void* get0();
    virtual int process(void* elem, void* obj, int* out, int arg);
};

extern "C" int fn_27_775AC(Object* obj, void* data, unsigned int* flags, int arg3) {
    void* container = *(void**)((char*)data + 0xd8);
    Slot* slot = *(Slot**)((char*)container + 0x74);
    short index = obj->head;
    while (index >= 0) {
        int sp8 = 0;
        if (slot->process((char*)lbl_27_bss_2BEC.data + index * 16, data, &sp8, arg3) == 0) {
            return 0;
        }
        *flags |= sp8;
        index = lbl_27_bss_2BEC.links[index];
    }
    return 1;
}
