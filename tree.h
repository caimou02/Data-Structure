typedef char data_t;

typedef struct node_t{
	data_t data;
	struct node_t * left;
	struct node_t * right;
}bitree;

bitree * tree_create();
void preorder(bitree * r);//先序
void inorder(bitree * r);//中序
void postorder(bitree * r);//后序
void layerorder(bitree * r);//层次

