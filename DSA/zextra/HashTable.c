#include <stdio.h>
struct hash
{
    int key;
    int value;
    struct hash *next;
};
int n;
int find(struct hash **hash, int key)
{
    int key1 = key % n;
    if (hash[key1] == NULL)
    {
        printf("KEY not found\n");
        return -99999;
    }
    if (key == hash[key1]->key)
        return hash[key1]->value;
    return findInLinkedList(&(hash[key1]->next), key);
}
int findInLinkedList(struct hash **hash, int key)
{
    if ((*hash) == NULL)
    {
        printf("KEY not found\n");
        return -99999;
    }
    if ((*hash)->key == key)
        return (*hash)->value;
    return findInLinkedList(&((*hash)->next), key);
}
void insertInLinkedList(struct hash **hash, int key, int val)
{
    if ((*hash) == NULL)
    {
        (*hash) = (struct hash *)malloc(sizeof(struct hash));
        (*hash)->key = key;
        (*hash)->value = val;
        (*hash)->next = NULL;
    }
    else
        insertInLinkedList(&((*hash)->next), key, val);
}
void insert(struct hash **hash, int key, int val)
{
    int key1 = key % n;
    if (hash[key1] == NULL)
    {
        hash[key1] = (struct hash *)malloc(sizeof(struct hash));
        hash[key1]->key = key;
        hash[key1]->value = val;
        hash[key1]->next = NULL;
    }
    else
        insertInLinkedList(&(hash[key1]->next), key, val);
}
int main()
{
    printf("Enter n: ");
    scanf("%d", &n);
    struct hash **hash;
    hash = (struct hash *)malloc(sizeof(struct hash) * n);
    for (int i = 0; i < n; i++)
        hash[i] = NULL;
    insert(hash, 5, 2);
    insert(hash, 3, 8);
    insert(hash, 15, 3);
    insert(hash, 6, 12);
    printf("%d", find(hash, 2));
}