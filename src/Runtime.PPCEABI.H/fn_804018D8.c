extern char lbl_80599F78[3][0x890];

int fn_804035BC(void* buffer);
int fn_804035B4(void* buffer);

void fn_804018D8(int index) {
    if (index != -1 && index >= 0 && index < 3) {
        char* buffer = lbl_80599F78[index];
        fn_804035BC(buffer);
        ((int*)buffer)[1] = 0;
        fn_804035B4(buffer);
    }
}
