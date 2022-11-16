typedef struct TERM;
void append(TERM* poly, double coef, int expon, int arr);
void sort(TERM* poly, int n);
void print(TERM* poly, int n);
void poly_add(TERM* a, int asize, TERM* b, int bsize, TERM* c);
void poly_minu(TERM* a, int asize, TERM* b, int bsize, TERM* c);
