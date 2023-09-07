#include <stdio.h>
#include <string.h>
#define n strlen(g)
char t[28], cs[28], g[28];
int a, e, c, b;
void xor () {
    for (c = 1; c < n; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
} void crc()
{
    for (e = 0; e < n; e++)
        cs[e] = t[e];
    do
    {
        if (cs[0] == '1')
            xor();
        cs[c] = cs[c + 1];
        cs[c] = t[e++];
    } while (e <= a + n - 1);
}
int main()
{
    int flag = 0;
    do
    {
        printf("\n1.crc12\n2.crc16\ncrc ccit\n4.exit\n\nEnter your option.");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            strcpy(g, "1100000001111");
            break;
        case 2:
            strcpy(g, "11000000000000101");
            break;
        case 3:
            strcpy(g, "10001000000100001");
            break;
        case 4:
            return 0;
        }
        printf("\n enter data:");
        scanf("%s", t);
        printf("\n-----------------------\n");
        printf("\n generating polynomial:%s", g);
        a = strlen(t);
        for (e = a; e < a + n - 1; e++)
            t[e] = '0';
        printf("\n--------------------------\n");
        printf("modified data is:%s", t);
        printf("\n-----------------------\n");
        crc();
        printf("checksum is:%s", cs);
        for (e = a; e < a + n - 1; e++)
            t[e] = cs[e - a];
        printf("\n-----------------------\n");
        printf("\n final codeword is : %s", t);
        printf("\n------------------------\n");
        printf("\ntest error detection 0(yes) 1(no)?:");
        scanf("%d", &e);
        if (e == 0)
        {
            do
            {
                printf("\n\tenter the position where error is to be inserted:");
                scanf("%d", &e);
            } while (e == 0 || e > a + n - 1);
            t[e - 1] = (t[e - 1] == '0') ? '1' : '0';
            printf("\n-----------------------\n");
            printf("\n\tErroneous data:%s\n", t);
        }
        crc();
        for (e = 0; (e < n - 1) && (cs[e] != '1'); e++)
            ;
        if (e < n - 1)
            printf("Error detected\n\n");
        else
            printf("\n No error detected \n\n");
        printf("\n-----------------------");
    } while (flag != 1);
}