typedef struct NODELINK;
typedef struct NODE;
void append(struct NODELINK* poly, double coef, int expon);
void erase(struct NODELINK* poly);
void sort(struct NODELINK* poly);
void print(struct NODELINK* poly);
struct NODELINK* poly_add(struct NODELINK* a, struct NODELINK* b);
struct NODELINK* poly_minu(struct NODELINK* a, struct NODELINK* b);



