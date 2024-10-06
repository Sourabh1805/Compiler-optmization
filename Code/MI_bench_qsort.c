#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXARRAY 60000 /* Maximum number of vectors */
#define MAX_COORDINATE 1000 /* Maximum value for x, y, z coordinates */

/* Structure for a 3D vertex */
struct my3DVertexStruct {
    int x, y, z;
    double distance;
};

/* Comparison function for qsort */
int compare(const void *elem1, const void *elem2) {
    double distance1, distance2;
    distance1 = (*((struct my3DVertexStruct *)elem1)).distance;
    distance2 = (*((struct my3DVertexStruct *)elem2)).distance;
    return (distance1 > distance2) ? 1 : ((distance1 == distance2) ? 0 : -1);
}

/* Function to generate random 3D vectors */
void generate_random_vectors(struct my3DVertexStruct *array, int count) {
    for (int i = 0; i < count; i++) {
        array[i].x = rand() % (2 * MAX_COORDINATE) - MAX_COORDINATE; // Random value between -MAX_COORDINATE and +MAX_COORDINATE
        array[i].y = rand() % (2 * MAX_COORDINATE) - MAX_COORDINATE;
        array[i].z = rand() % (2 * MAX_COORDINATE) - MAX_COORDINATE;
        array[i].distance = sqrt(pow(array[i].x, 2) + pow(array[i].y, 2) + pow(array[i].z, 2));
    }
}

int main(int argc, char *argv[]) {
    clock_t start = clock();
    struct my3DVertexStruct array[MAXARRAY];
    int count = 0;

    if (argc < 2) {
        
        count = MAXARRAY; // Generate MAXARRAY random vectors
        generate_random_vectors(array, count);
    } else {
        FILE *fp = fopen(argv[1], "r");
        int x, y, z;

        if (fp == NULL) {
            fprintf(stderr, "Error opening file.\n");
            exit(-1);
        }

        while ((fscanf(fp, "%d", &x) == 1) && (fscanf(fp, "%d", &y) == 1) && (fscanf(fp, "%d", &z) == 1) && (count < MAXARRAY)) {
            array[count].x = x;
            array[count].y = y;
            array[count].z = z;
            array[count].distance = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
            count++;
        }
        fclose(fp);
    }

    
    qsort(array, count, sizeof(struct my3DVertexStruct), compare);

  

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%lld\n");
    printf("%f\n", time_spent);

    return 0;
}
