#pragma force_active on
struct VillageObject {
    int padding[2];
};

struct VillageElement {
    int data[26];
};

extern "C" VillageElement* fn_70_9174(VillageObject* object, int index)
{
    int shift = *(int*)((char*)object + 8) >> 30;
    int adjusted = shift + index;
    if (adjusted < 1) {
        adjusted = adjusted;
    } else {
        adjusted = adjusted - 1;
    }
    return (VillageElement*)((char*)object + adjusted * 0x68 + 0x0C);
}
