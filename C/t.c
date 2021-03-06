#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

typedef struct {
  char *name;
  long long lasted;
} sort_file;

/*

#define comp(member) comp_##member
#define comp_build(member)                          \
int comp_##member(const void *pa, const void *pb)   \
{                                                   \
    const struct data *a = pa, *b = pb;             \
    return a->member - b->member;                   \
}


static __inline__ sort_file** sort(sort_file **d, int count) {
  int i, j;
  for (i = 0; i < count; i++) {
    sort_file *tmp = d[i];
    for (j = i; j >= 1 && tmp->lasted > ((sort_file *)d[j - 1])->lasted; j--)
      d[j] = d[j - 1];
    d[j] = tmp;
  }
}

int comp(const void *pa, const void *pb, unsigned long offset)
{
    const int *a = (const int *) (pa + offset);
    const int *b = (const int *) (pb + offset);

    return (*a > *b) - (*a < *b);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void sort(void *v[], int left, int right, unsigned long offset, int
(*comp)(const void *, const void *, unsigned long))
{
    int i, last;

    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left], offset) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    sort(v, left, last - 1, offset, comp);
    sort(v, last + 1, right, offset, comp);
}

*/

int compare(const void *s1, const void *s2) {
  sort_file *e1 = (sort_file *)s1;
  sort_file *e2 = (sort_file *)s2;
  return (*(int *)e1->lasted - *(int *)e2->lasted);
}
int main(int argc, char *argv[]) {
  DIR *dir;
  struct dirent *ent;
  struct stat attr;

  int size = 10;
  char **filesArray = malloc(
      size * sizeof(char *)); //[20]; //=(char*) malloc (size * sizeof(char));
  int count = 0;
  sort_file **lsf = malloc(size * sizeof(sort_file *));
  if ((dir = opendir(".")) != NULL) {
    while ((ent = readdir(dir)) != NULL) {

      if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0 ||
          ent->d_type == DT_DIR) {
        continue;
      } else {
        filesArray[count] = strdup(ent->d_name);
        stat(ent->d_name, &attr);
        sort_file *s = (sort_file *)malloc(sizeof(sort_file));

        s->name = strdup(ent->d_name);
        s->lasted = attr.st_mtime * 1000 + attr.st_mtim.tv_nsec / 1000000;

        lsf[count] = s;

        // printf("%s\n", filesArray[count]);
      }
      if (++count > size) {
        size *= 2;
        lsf = realloc(lsf, size * sizeof(sort_file *));
        filesArray = realloc(filesArray, size * sizeof(char *));

        // filesArray =realloc(filesArray,  size*sizeof(char));
      }
    }
    closedir(dir);
  } else { /* could not open directory */
    perror("Could not open directory");
  }
  int i, j;
  for (i = 0; i < count - 1; i++)
    for (j = 0; j < count - i - 1; j++) {
      if (lsf[j]->lasted > lsf[j + 1]->lasted) {
        sort_file *temp = lsf[j];
        lsf[j] = lsf[j + 1];
        lsf[j + 1] = temp;
      }

      /*
      printElementsInArray(a, n);
      printf("\n");
      */
    }
  while (count--) {
    printf("%lld --- %s\n", lsf[count]->lasted, lsf[count]->name);
  }
  printf("%s\n", filesArray[0]);

  return 0;
}

void freeMemory(sort_file *sf, int n) {
  for (int i = 0; i < n; i++) {
    free(sf[i].name);
  }
  free(sf);
}
