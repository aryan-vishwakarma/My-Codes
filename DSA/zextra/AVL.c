#include <stdio.h>
#include <stdlib.h>
struct train{
    int key;
    struct train *left;
    struct train *right;
    int height;
    char name[100];
};
int max(int a, int b);
int height(struct train *N){
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b){
    return (a > b) ? a : b;
}
struct train* newNode(int key, char name[]){
    struct train *node = (struct train *)malloc(sizeof(struct train));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    strcpy(node->name, name);
    return (node);
}
struct train* rightRotate(struct train *y){
    struct train *x = y->left;
    struct train *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct train *leftRotate(struct train *x){
    struct train *y = x->right;
    struct train *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(struct train *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct train *insert(struct train *node, int key, char name[]){
    if (node == NULL)
        return (newNode(key, name));

    if (key < node->key)
        node->left = insert(node->left, key, name);
    else if (key > node->key)
        node->right = insert(node->right, key, name);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
struct train* minValueNode(struct train *node){
    struct train *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct train* deleteNode(struct train *root, int key){
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if ((root->left == NULL) || (root->right == NULL)){
            struct train *temp = root->left ? root->left : root->right;
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else{
            struct train *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct train* search(struct train* node, int key){
    if(node==NULL){
        printf("Couldn't find the train number\n");
        return;
    }
    if(node->key == key)
    return(node);
    if(node->key>key)
    return(search(node->left, key));
    else
    return(search(node->right, key));
}
int main()
{
    struct train *root = NULL;
    root = insert(root, 15609, "Abadh Assam Express");
    root = insert(root, 18106, "Bhubaneshwar - Rourkela Intercity Express");
    root = insert(root, 54022, "Delhi Nizamuddin - Bulandshahr Passenger");
    root = insert(root, 22656, "Hazrat Nizamuddin Thiruvananthapuram Super Fast Express");
    root = insert(root, 11472, "Jabalpur - Indore Express");
    root = insert(root, 14084, "Mahananda Express");
    root = insert(root, 58835, "Nagpur Ramakona Chhindwara Passenger");
    root = insert(root, 56808, "Tiruchirappalli - Vriddhachalam Passenger");
    root = insert(root, 16628, "West Coast Express");
    int t;
    printf("\nEnter train number to be searched: ");
    scanf("%d",&t);
    struct train *result = search(root, t);
    if(result!=NULL){
        printf("Train found\nTrain no. : %d\nName of train: %s\n",result->key,result->name);
    }
    return 0;
}