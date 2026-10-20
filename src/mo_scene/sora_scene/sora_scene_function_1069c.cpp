#pragma force_active on
struct Node { Node* next; };
struct Iter { char pad[0xc]; Node* cur; };
extern "C" void fn_1_1069C(Iter* it) { it->cur = it->cur->next; }
