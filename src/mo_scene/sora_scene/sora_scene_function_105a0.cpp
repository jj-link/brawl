#pragma force_active on
struct Node { char pad[4]; Node* next; };
struct Iter { char pad[0xc]; Node* cur; };
extern "C" void fn_1_105A0(Iter* it) { it->cur = it->cur->next; }
