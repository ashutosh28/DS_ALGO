int *a = null;
*a = 1000;
printf("%d",*a);

2d array in one malloc

mutex and semphore

int *a = malloc(10*sizeof(int));
a++;
free(a);
