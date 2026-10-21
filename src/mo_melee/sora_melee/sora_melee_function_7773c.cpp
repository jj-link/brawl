#pragma force_active on
struct Pool {
    void* data;
    short* links;
    short freeHead;
    short count;
    int other[2];
    bool valid(int index) const { return index >= 0 && index < count; }
    void release(short index) {
        if (valid(index)) {
            links[index] = freeHead;
            freeHead = index;
        }
    }
};
extern Pool lbl_27_bss_2BEC;
struct Object {
    int unknown;
    short head;
};
extern "C" void fn_27_7773C(Object* object) {
    short old;
    short index = object->head;
    if (index < 0) return;
    if (lbl_27_bss_2BEC.valid(index)) {
        while (index >= 0) {
            old = index;
            short* links = lbl_27_bss_2BEC.links;
            index = links[index];
            if (lbl_27_bss_2BEC.valid(old)) {
                links[old] = lbl_27_bss_2BEC.freeHead;
                lbl_27_bss_2BEC.freeHead = old;
            }
        }
    }
    object->head = -1;
}
