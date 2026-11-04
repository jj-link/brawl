#pragma force_active on
extern "C" {
int fn_27_70004(void*);
void fn_27_143EFC(void*, void*);
void* getNode__6utListFUl(void*, unsigned long);
void remove__6utListFP10utListNode(void*, void*);
void addTail__6utListFP10utListNode(void*, void*);

void fn_27_145140(char* arg0) {
    char* temp_r30 = arg0 + 4;
    if (*(unsigned char*)(arg0 + 0x14) == 3 &&
        fn_27_70004(temp_r30 + 0x1C) != 0) {
        fn_27_143EFC(arg0, temp_r30);
        *(unsigned char*)(temp_r30 + 0x10) = 4;
    }
    if (*(unsigned char*)(temp_r30 + 0x10) == 4) {
        char* var_r29 = (char*)getNode__6utListFUl(arg0 + 0x1088, 0);
        while (var_r29 != 0) {
            temp_r30 = *(char**)var_r29;
            if (fn_27_70004(var_r29 + 0x1C) != 0) {
                fn_27_143EFC(arg0, var_r29);
                *(unsigned char*)(var_r29 + 0x10) = 4;
            }
            if (*(unsigned char*)(var_r29 + 0x10) == 4) {
                remove__6utListFP10utListNode(arg0 + 0x1088, var_r29);
                addTail__6utListFP10utListNode(arg0 + 0x1094, var_r29);
            }
            var_r29 = temp_r30;
        }
    }
}
}