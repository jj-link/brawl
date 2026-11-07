#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();

    unsigned int flags;
};

extern "C" void fn_27_2AED60(
    Object_vptr_0* self, int start, const int* value, int count
) {
    if (count != 0) {
        if (count + start >= self->slot3()) {
            count = self->slot3() - start;
        }

        int index = (int)((self->flags << 8) & 0xFF800000) >> 24;
        while (count > 0) {
            if (start > 0) {
                --start;
            } else {
                --count;
                *(int*)((char*)self + index * 12 + 0xc) = *value;
            }

            index = *(signed char*)((char*)self + index * 12 + 0x11);
            if (index < 0) {
                break;
            }
        }
    }
}
