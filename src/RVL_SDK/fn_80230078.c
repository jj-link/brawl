#pragma force_active on
typedef struct Node {
    struct Node *next;
    int unk4;
    int unk8;
    int unkC;
} Node;

typedef struct Head {
    Node *first;
    int unk4;
    int unk8;
} Head;

int fn_80230078(Head *arg0, int arg1) {
    int temp_r5;
    Node *var_r6;
    int var_r7;
    int var_r8;
    int temp_r9;
    int temp_r0;
    int temp_r0_2;

    var_r6 = arg0->first;
    var_r7 = 0;
    while (var_r6 != 0 && var_r6->unkC <= 0) {
        var_r6 = var_r6->next;
        var_r7 += 1;
    }
    var_r8 = arg1;
    while (var_r6 != 0 && var_r8 > 0) {
        temp_r9 = var_r6->unkC;
        temp_r5 = temp_r9 - var_r8;
        var_r6->unkC = temp_r5;
        if (temp_r5 <= 0) {
            var_r6->unkC = 0;
            var_r7 += 1;
        }
        var_r8 -= temp_r9;
        var_r6 = var_r6->next;
    }
    temp_r0 = arg0->unk8;
    if (temp_r0 > 0) {
        temp_r0_2 = temp_r0 - arg1;
        arg0->unk8 = temp_r0_2;
        if (temp_r0_2 < 0) {
            arg0->unk8 = 0;
        }
    }
    return var_r7;
}
