#include <stdio.h>
#include <stdlib.h>

struct heapData {
	int a;
	int b;
	char c;
};

int main()
{
    int num = 52;
    int *ptr;

	struct heapData *hd;
	hd = (struct heapData *)malloc(sizeof(struct heapData));

	(*hd).a = 12;
	hd->b = 19;
	hd->c = 'z';

    ptr = &num;
    //printf("%d - %d", num, *heapPtr);
	//printf("heap array: %d\n", heapPtr[0]);
    printf("Size of headp Data pointer variable %d\n", sizeof(*hd));
	printf("heap data struct %d %d %c\n", hd->a, hd->b, hd->c);
	printf("heap addresses %pd\n",  &hd);
	//free(heapPtr);
	free(hd);
}
