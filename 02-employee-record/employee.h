struct namerec
{
    char last[15];
    char first[15];
    char middle[15];
};

struct payrecord
{
    int id;
    struct namerec name;
    float hours, rate;
    float regular, overtime;
    double gross, tax_withheld, net;
};

typedef struct payrecord payrecord;

/* INPUTS */
void readName(payrecord payroll[], int i);
void readRecords(payrecord payroll[], int n);

/* OUTPUTS */
void printName(payrecord payroll[], int i);
void printSummary(double gross, double tax);
void printRecords(payrecord payroll[], int n);

/* COMPUTATIONS */
double calcRecords(payrecord payroll[], int n, double *taxptr);


/* If linux or Mac OS */
#if defined(__linux__) || defined(__APPLE__)
#define CLEAR system("clear")
#define PAUSE system("read")
#else
/* else windows */
#define CLEAR system("cls")
#define PAUSE system("pause")
#endif

#define EXIT system("exit")
