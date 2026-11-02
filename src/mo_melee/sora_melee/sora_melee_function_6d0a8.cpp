#pragma force_active on
struct Node { char pad[0x1C]; };
struct NodeArray { virtual void slot0(); virtual Node* get(int); };
struct Work { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void set(float, int); };
struct Modules { char pad[0x44]; Work* work; };
struct Data { char pad[0xD8]; Modules* modules; };
struct Accessor { char pad[0x44]; Data* data; };
struct Object { char pad[0x48]; NodeArray* nodes; };
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6D0A8(Object* self, int index, int value, int workIndex) {
    Node* node = self->nodes->get(index);
    fn_27_6F30C((char*)node + 0x1C)->data->modules->work->set((float)value, workIndex);
}
