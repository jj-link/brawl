#pragma force_active on
extern "C" {
extern int g_BlocMagic;

struct Node {
    int val;
};

struct Holder {
    char pad[8];
    Node* node;
};

int fn_40_33C4(Holder* h)
{
    return g_BlocMagic == h->node->val;
}
}
