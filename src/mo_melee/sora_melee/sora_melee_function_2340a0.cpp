#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_4BCB8[];
extern "C" char lbl_27_data_4BCF8[];
extern "C" char __RTTI__10gfCallBack[];

struct Node { Node* next; int pad; int type; };
struct Object { char pad[0x20]; Node* first; Node* second; };

extern "C" int fn_27_2340A0(Object* self) {
    Node* node = self->first;
    if (node) {
        while (node) {
            if (node->type == 9 && !*(unsigned char*)((char*)__dynamic_cast(node, 4, lbl_27_data_4BCB8, lbl_27_data_4BCF8, 0) + 0xb1))
                return 0;
            node = (Node*)__dynamic_cast(node->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
        }
    }
    node = self->second;
    if (node) {
        while (node) {
            if (node->type == 9 && !*(unsigned char*)((char*)__dynamic_cast(node, 4, lbl_27_data_4BCB8, lbl_27_data_4BCF8, 0) + 0xb1))
                return 0;
            node = (Node*)__dynamic_cast(node->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
        }
    }
    return 1;
}