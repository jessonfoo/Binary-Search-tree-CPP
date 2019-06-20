struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

struct Node {
    Bid data;
    Node *left;
    Node *right;
};

BinarySearchTree::BinarySearchTree() {
// initialize housekeeping variables
    root = NULL;
}


void Node::DestroyRecursive(Node node)
{
    if (node)
    {
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }
}


BinarySearchTree::~BinarySearchTree() {

    DestroyRecursive(node->root);

}


void BinarySearchTree::InOrder() {
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data.bidId);
        inorder(root->right);
    }

}

Node * minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* BinarySearchTree::deleteNode(Node *root,string bidId) {



    if (root == NULL) return root;

    if (bidId < root->data.bidId)
        root->left = deleteNode(root->right,bidId);

    else if (bidId > root->data.bidId)
        root->right = deleteNode(root->right, bidId);

    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->data.bidId = temp->data.bidId;

        root->right = deleteNode(root->right, temp->data.bidId);
    }
}


void BinarySearchTree::Remove(string bidId) {
// FIXME (4a) Implement removing a bid from the tree

    deleteNode(root,bidid);
}

Bid BinarySearchTree::Search(string bidId) {
// FIXME (3) Implement searching the tree for a bid
    Bid bid;

    if (root == NULL || root->data.bidId == bidId){
        bid.bidId = bidId;
        bid.title = root->data.title;
        bid.fund = root->data.fund;
        bid.amount = root->data.amount;
        return bid;
    }


    if (root->data.bidId < bidId)
        return search(root->right, bidId);


    return search(root->left, bidId);
    return bid;
}


Node *newNode(Bid bid)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data.bid = bid.bidId;
    temp->data.title = bid.title;
    temp->data.amount = bid.amount;
    temp->data.fund = bid.fund;
    temp->left = temp->right = NULL;
    return temp;
}

Node* BinarySearchTree::insertNode(Node* node, Bid bid) {
// FIXME (2b) Implement inserting a bid into the tree

    if (node == NULL) return newNode(bid);

    if (bid.bidId < node->data.bidId)
        node->left = insertNode(node->left, bid);
    else
        node->right = insertNode(node->right, bid);


}


void BinarySearchTree::Insert(Bid bid) {
// FIXME (2a) Implement inserting a bid into the tree
    Node p = insertNode(root, bid)
    p->data.bidId = bid.bidId;
    p->data.title = bid.title;
    p->data.fund = bid.fund;
    p->daat.amount = bid.amount;
}


void BinarySearchTree::addNode(Node* node, Bid bid) {
// FIXME (2b) Implement inserting a bid into the tree
    Node p = insertNode(node, bid)
    p->data.bidId = bid.bidId;
    p->data.title = bid.title;
    p->data.fund = bid.fund;
    p->daat.amount = bid.amount;
}
