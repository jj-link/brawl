typedef unsigned char u8;

struct FILE {
    u8 bytes[10];
    u8 error;
};

extern int _fseek(struct FILE*, unsigned long, int);

void fn_803F5EAC(struct FILE* file) {
    file->error = 0;
    _fseek(file, 0, 0);
    file->error = 0;
}
