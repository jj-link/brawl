#pragma force_active on
struct MD5State {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int count0;
    unsigned int count1;
};

void fn_8035B34C(struct MD5State *s) {
    s->count1 = 0;
    s->count0 = 0;
    s->a = 0x67452301;
    s->b = 0xEFCDAB89;
    s->c = 0x98BADCFE;
    s->d = 0x10325476;
}
