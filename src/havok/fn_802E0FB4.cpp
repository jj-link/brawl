#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern char lbl_804885E8[];
extern void* lbl_805A0EC8;
class SoHeapAllocator { public: virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4(); virtual void free(void*, unsigned short, int); };
extern SoHeapAllocator* lbl_805A0EB8;
class Ref { public: virtual void destroy(int); unsigned short active; short count; };
template <int Shift> struct Array {
    void* data; unsigned int size; unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << Shift, 0x15); }
    void cleanup() { if ((unsigned int)this && isOwned()) dealloc(); }
    ~Array() { if (isOwned()) dealloc(); }
};
struct Object {
    void* vtable; unsigned short type; char pad[0x16]; Ref* ref; char pad2[0x20];
    Array<3> array2; Array<4> array1;
};
extern "C" Object* fn_802E0FB4(Object* self, int flag) {
    if (self) {
        Ref* ref = self->ref;
        self->vtable = lbl_804885E8;
        if (ref) {
            if (ref->active != 0) {
                ref->count -= 1;
                if (ref->count == 0) {
                    if (ref != 0) ref->destroy(1);
                }
            }
        }
        self->array1.cleanup();
        if ((unsigned int)self + 0x1c)
            self->array2.cleanup();
        if (flag > 0) lbl_805A0EB8->free(self, self->type, 0x13);
    }
    return self;
}